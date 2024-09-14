{
    description = "Local version";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
        HelloLibrary.url = "github:goltsmannn/nix_cmake_project";
    };
    outputs = { self, nixpkgs, HelloLibrary, ...} @inputs:
    let
       system = "aarch64-darwin";
       overlay = final: prev: {
            helloapp = final.callPackage ./default.nix {};
        };
       overlays = [HelloLibrary.overlays.default overlay];
        pkgs = import nixpkgs{
            system = system;
            overlays = [self.overlays.default];
        };
    in {
        overlays.default = nixpkgs.lib.composeManyExtensions overlays;

        packages.${system}.default = pkgs.helloapp;
    };
}