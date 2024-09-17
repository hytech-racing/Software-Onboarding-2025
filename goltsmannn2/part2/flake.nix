{
    description = "Software Onboarding Lab 2 Part 2 Flake";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
    };

    outputs = { self, nixpkgs, ...} @inputs:
    let
        system = "aarch64-darwin";
        overlay = final: prev: {
            hellolib = final.callPackage ./hellolib.nix {};
            helloapp = final.callPackage ./default.nix {};

        };
        overlays = [overlay];
        pkgs = import nixpkgs {
            system = "aarch64-darwin";
            overlays = [ self.overlays.default ];
        };
    in
    {
        packages.${system}.default = pkgs.helloapp;
        overlays.default = nixpkgs.lib.composeManyExtensions overlays;
    };
}