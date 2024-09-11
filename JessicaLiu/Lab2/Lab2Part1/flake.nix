{
    description = "Lab 02 Flake";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
    };

    outputs = { self, nixpkgs }:

    let
        helloworld_lib_overlay = final: prev: {
            helloworld_lib = final.callPackage ./default.nix { };
        };

        my_overlays = [ helloworld_lib_overlay ];

        pkgs = import nixpkgs {
            system = "x86_64-linux";
            overlays = [ self.overlays.default ];
        };

        in {
            packages.x86_64-linux.default = pkgs.helloworld_lib;
            overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
        };
}