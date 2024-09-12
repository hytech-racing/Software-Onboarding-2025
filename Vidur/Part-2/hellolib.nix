{ stdenv, cmake }:

stdenv.mkDerivation rec {
    pname = "hellolib";
    version = "1.0.0";
    src = ./hellolib; # Path to your source directory

    nativeBuildInputs = [ cmake ];
}