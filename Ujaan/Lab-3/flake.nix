{
  description = "Protobuf UDP Communication";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs = { self, nixpkgs }: 
  let
    system = "x86_64-linux";
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
