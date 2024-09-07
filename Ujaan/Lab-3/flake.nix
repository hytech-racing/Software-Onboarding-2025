{
  description = "Protobuf UDP Communication";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      defaultPackage.${system} = pkgs.mkShell {
        nativeBuildInputs = [ pkgs.cmake ];
        buildInputs = [ pkgs.protobuf pkgs.gcc ];
      };
    };
}
