{stdenv, cmake, protobuf}:

stdenv.mkDerivation rec {
  pname = "woo";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ protobuf ];
}