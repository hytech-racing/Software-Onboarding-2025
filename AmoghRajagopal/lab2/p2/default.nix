{stdenv, cmake, hellolib}:

stdenv.mkDerivation rec {
    pname = "HyTech_Lab2_P2_Executable";
    version = "0.1.0";
    src = ./helloapp;
    nativeBuildInputs = [cmake];
    buildInputs = [hellolib];
}