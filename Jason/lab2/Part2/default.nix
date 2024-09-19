{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_lib";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}