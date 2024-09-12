{ stdenv, cmake, hello_lib }:

stdenv.mkDerivation rec {
  pname = "hello_app";
  version = "0.1.0";
  src = ./src;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hello_lib ];
}