{stdenv, cmake}:

stdenv.mkDerivation rec {
    pname = "HyTech_Lab1_P2";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [cmake];
}
