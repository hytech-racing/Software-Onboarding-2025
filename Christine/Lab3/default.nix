{ stdenv, cmake, protobuf }:

stdenv.mkDerivation {
    pname = "program";
    version = "0.1.0";
    src = ./.;

    nativeBuildInputs = [ cmake ];
    buildInputs = [ protobuf ];
}