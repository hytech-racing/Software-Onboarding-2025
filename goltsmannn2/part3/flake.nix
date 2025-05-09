{
    description = "software_onboarding_lab_3_flake";
    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };

    outputs = { self, nixpkgs, ...} @inputs:
    let
        system = "aarch64-darwin";
        overlay = final: prev: {
            defaultPackage = final.callPackage ./default.nix {};
        };
        overlays = [overlay];
        pkgs = import nixpkgs {
            system = system;
            overlays = [self.overlays.default];
        };
    in
    {
        overlays.default = nixpkgs.lib.composeManyExtensions overlays;
        packages.${system}.default = pkgs.defaultPackage;
        legacyPackages.${system} =
            import nixpkgs {
              inherit system;
              inherit overlays;
            };
    };
}