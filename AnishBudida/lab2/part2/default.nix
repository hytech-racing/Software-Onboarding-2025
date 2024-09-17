{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "hello_world";
  version = "0.1.0";
  src = ./helloapp;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}
