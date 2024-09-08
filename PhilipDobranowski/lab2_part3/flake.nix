{
  description = "Hello World part 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    hellolib.url = "github:RenchTG/nix-hello-lib";
  };

  outputs = { self, nixpkgs, hellolib }:
    let
      hello_overlay = final: prev: rec {
        hello = final.callPackage ./default.nix { };
      };

      my_overlays = [ hello_overlay ];

      pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default hellolib.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-linux.default = pkgs.hello;
    };
}