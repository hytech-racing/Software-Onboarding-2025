{
  description = "Test Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {
    packages = {
      aarch64-darwin = let
        pkgs = nixpkgs.legacyPackages.aarch64-darwin;
      in
      {
        hello = pkgs.hello;
        default = pkgs.callPackage ./default.nix {};
      };
    };
  };
}