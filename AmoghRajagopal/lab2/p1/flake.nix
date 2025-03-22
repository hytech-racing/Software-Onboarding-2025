{
  description = "lab2 flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      # Define overlay properly
      overlay = final: prev: {
        nix_cmake = final.callPackage ./default.nix { };
      };

      my_overlays = [ overlay ];

      # Apply overlays correctly
      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = my_overlays;
      };

    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

      packages.aarch64-darwin = {
        nix_cmake = pkgs.nix_cmake;
        default = pkgs.nix_cmake;
      };
    };
}
