{
    description = "HyTech_Lab2_P3";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
        hellolib.url = "github:acr12856/p3Lib";
    };
    outputs = { self, nixpkgs, hellolib, ...} @inputs:
    let
       system = "aarch64-darwin";
       overlay = final: prev: {
            helloapp = final.callPackage ./default.nix {};
        };
       overlays = [hellolib.overlays.default overlay];
        pkgs = import nixpkgs{
            system = system;
            overlays = [self.overlays.default];
        };
    in {
        overlays.default = nixpkgs.lib.composeManyExtensions overlays;

        packages.${system}.default = pkgs.helloapp;
    };
}