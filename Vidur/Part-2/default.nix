let
  pkgs = import <nixpkgs> {};
in
pkgs.stdenv.mkDerivation rec {
    pname = "HelloWorld";
    version = "1.0.0";
    src = ./.;

    nativeBuildInputs = [ pkgs.cmake ];
}