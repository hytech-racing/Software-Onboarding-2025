{ stdenv, cmake, helloworld_lib }:

stdenv.mkDerivation rec {
  pname = "hello_world";
  version = "0.1.0";
  src = ./helloapp;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ helloworld_lib ];
}