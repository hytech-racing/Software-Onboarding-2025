{
  description = "Test Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {

    packages.aarch64-darwin.hello = nixpkgs.legacyPackages.aarch64-darwin;

    packages.aarch64-darwin.default = self.packages.aarch64-darwin;

    in
    {
      default = pkgs.callPackage ./default.nix {};
    };

  };
}
