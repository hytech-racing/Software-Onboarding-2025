{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "main";
  version = "0.1.0";
  src = ./main;
  nativeBuildInputs = [ cmake ];
}