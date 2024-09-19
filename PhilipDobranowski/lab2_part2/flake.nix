{
  description = "Hello World part 2 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      hello_overlay = final: prev: rec {
        hellolib = final.callPackage ./hellolib.nix { };
        hello = final.callPackage ./default.nix { inherit hellolib; };
      };

      my_overlays = [ hello_overlay ];

      pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-linux.default = pkgs.hello;
    };
}