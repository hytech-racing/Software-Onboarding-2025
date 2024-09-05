{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_lib";
  version = "0.1.2";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}