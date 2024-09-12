{
  description = "Lab 2 Part 2 Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
  let
    hello_world_overlay = final: prev: rec {
      hellolib = final.callPackage ./hellolib.nix { };
      hello_world = final.callPackage ./default.nix { inherit hellolib; };
    };
    my_overlays = [ hello_world_overlay ];

    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };
    in
    {
      packages.x86_64-linux.default = pkgs.hello_world;
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
