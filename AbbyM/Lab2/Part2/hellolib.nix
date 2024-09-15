{ stdenv, cmake }:

stdenv.mkDerivation rec {
    pname = "HelloWorldLibrary";
    version = "0.1.0";
    src = ./hellolib;
    nativeBuildInputs = [ cmake ];
}