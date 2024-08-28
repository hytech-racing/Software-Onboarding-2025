{ stdenv, cmake, hello_package }:

stdenv.mkDerivation rec {
  pname = "main";
  version = "0.1.0";
  src = ./main;
  # Native build inputs are the inputs needed to evaluate (build) the derivation
  nativeBuildInputs = [ cmake ];
  # build inputs are the inputs needed to run the derivation downstream (puts it in the environemnt, think no import issues)
  buildInputs = [ hello_package ];
}