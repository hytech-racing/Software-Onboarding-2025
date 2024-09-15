{
    description = "Lab 02 Part 3 Flake";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
        utils.url = "github:numtide/flake-utils";
        hellolib.url = "github:jessicaliu06/hytech_software_onboarding";
    };

    outputs = { self, nixpkgs, utils, hellolib }:
        let
            helloworld_overlay = final: prev: rec {
                helloworld = final.callPackage ./default.nix {
                };
            };

            my_overlays = [ helloworld_overlay hellolib.overlays.default ];

            pkgs = import nixpkgs {
                system = "x86_64-linux";
                overlays = [ self.overlays.default hellolib.overlays.default ];
            };

            in {
                packages.x86_64-linux.default = pkgs.helloworld;
                overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
            };
}