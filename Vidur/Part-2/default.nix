let
  pkgs = import <nixpkgs> {};
  hellolib = pkgs.callPackage ./hellolib.nix {};
in
pkgs.stdenv.mkDerivation rec {
  pname = "HelloWorld";
  version = "1.0.0";
  src = ./helloapp;

  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ hellolib ];
}