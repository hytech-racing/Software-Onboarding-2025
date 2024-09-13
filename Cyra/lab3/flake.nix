{
  description = "flake lab 3";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "aarch64-darwin";

      main_overlay = final: prev: rec {
        main = final.callPackage ./default.nix { };
      };

      my_overlays = [ main_overlay ];

      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.aarch64-darwin.default = pkgs.main;
      
      legacyPackages.aarch64-darwin =
      import nixpkgs {
        inherit system;
        overlays = [
          (final: _: { lab3 = final.callPackage ./default.nix { }; })
        ];
      };
    };
}