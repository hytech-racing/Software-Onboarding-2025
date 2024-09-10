{ stdenv, cmake }:

stdenv.mkDerivation rec {
    pname = "Lab2";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
}