{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_package";
  version = "0.1.0";
  src = ./package;
  nativeBuildInputs = [ cmake ];
}