{
  description = "Lab 2 Part 3 Flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    hellolib.url = "github:anishthebud/georgiaTech";
  };

  outputs = { self, nixpkgs, hellolib }: 
  let
    hello_world_overlay = final: prev: rec {
      hello_world = final.callPackage ./default.nix { };
    };
    my_overlays = [ hellolib.overlays.default hello_world_overlay ];

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
