{
  description = "tyler's flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };


  outputs = { self, nixpkgs, ...} @ inputs:
      let
        supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];
        supportedPackages = function: nixpkgs.lib.genAttrs supportedSystems (system: function nixpkgs.legacyPackages.${system});
      in {
        packages = supportedPackages (pkgs: {
          default = pkgs.callPackage ./default.nix {};
        });
      };
}