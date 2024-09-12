{
  description = "flake lab 3";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
  };

  outputs = { self, nixpkgs }:
  let
    system = "aarch64-darwin"
    legacyPackages = import nixpkgs {
      inherit system;
      overlays = [
        (final: _: { lab3 = final.callPackage ./default.nix { }; })
      ];
    };
  in {
    defaultPackage.${system} = legacyPackages.mkShell {
      nativeBuildInputs = [ legacyPackages.cmake ];
      buildInputs = [ legacyPackages.protobuf legacyPackages.gcc ];
    };

    legacyPackages.${system} = legacyPackages;
  };

}