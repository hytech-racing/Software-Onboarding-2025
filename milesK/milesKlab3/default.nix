{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "INSERTNAME";
  version = "0.1.0";
  src = ./INSERT;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ protobuf ]
}
