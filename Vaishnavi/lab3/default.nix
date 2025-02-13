{ stdenv, cmake, protobuf }:

stdenv.mkDerivation rec {
  pname = "ProtoBufUDP";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ protobuf ];
}