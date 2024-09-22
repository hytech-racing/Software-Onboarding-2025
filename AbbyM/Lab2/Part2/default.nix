{ stdenv, cmake, hello_lib }:

stdenv.mkDerivation rec {
    pname = "HelloWorldApp";
    version = "0.1.0";
    src = ./helloapp;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ hello_lib ];
}