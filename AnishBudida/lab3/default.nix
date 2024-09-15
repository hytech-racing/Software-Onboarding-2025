{ stdenv, cmake, protobuf }:
 
stdenv.mkDerivation rec {
  pname = "protoMessage";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ protobuf ];
}
