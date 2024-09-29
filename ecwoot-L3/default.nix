{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
    pname = "Socket";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ protobuf ];
}