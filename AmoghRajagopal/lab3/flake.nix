{
  description = "HyTech Lab 3 Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "aarch64-darwin";
    legacyPackages.aarch64-darwin =
      import nixpkgs {
        inherit system;
        overlays = [
          (final: _: { lab3 = final.callPackage ./default.nix { }; })
        ];
      };
  in {
    legacyPackages.${system} = legacyPackages.aarch64-darwin;
    defaultPackage.${system} = legacyPackages.aarch64-darwin.mkShell {
      nativeBuildInputs = [ legacyPackages.aarch64-darwin.cmake ];
      buildInputs = [ legacyPackages.aarch64-darwin.protobuf legacyPackages.aarch64-darwin.gcc ];
    };
  };
}
