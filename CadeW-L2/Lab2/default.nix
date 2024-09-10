{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
    pname = "Lab2";
    version = "0.1.0";
    src = ./helloapp;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ hellolib ];
}