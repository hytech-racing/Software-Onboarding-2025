{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "lab3";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ protobuf ]
}