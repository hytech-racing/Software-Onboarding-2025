{
    description = "Lab 02 Part 2 Flake";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
        utils.url = "github:numtide/flake-utils";
    };

    outputs = { self, nixpkgs, utils }:
        let
            helloworld_overlay = final: prev: rec {
                helloworld_lib = final.callPackage ./hellolib.nix { };
                helloworld = final.callPackage ./default.nix {
                    inherit helloworld_lib;
                };
            };

            my_overlays = [ helloworld_overlay ];

            pkgs = import nixpkgs {
                system = "x86_64-linux";
                overlays = [ self.overlays.default ];
            };

            in {
                packages.x86_64-linux.default = pkgs.helloworld;
                overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
            };
}