{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_library";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}