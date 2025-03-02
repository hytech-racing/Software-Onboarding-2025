{ stdenv, cmake, protobuf }:

stdenv.mkDerivation rec {
    pname = "HyTech_Lab3Protobuf";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ protobuf ];
}