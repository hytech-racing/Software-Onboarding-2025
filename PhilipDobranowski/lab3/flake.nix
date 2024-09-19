{
  description = "Lab 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";

      main_overlay = final: prev: rec {
        main = final.callPackage ./default.nix { };
      };

      my_overlays = [ main_overlay ];

      pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-linux.default = pkgs.main;
      
      legacyPackages.x86_64-linux =
      import nixpkgs {
        inherit system;
        overlays = [
          (final: _: { lab3 = final.callPackage ./default.nix { }; })
        ];
      };
    };
}