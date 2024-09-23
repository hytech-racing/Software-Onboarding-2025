{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello";
  version = "0.1.0";
  src = ./collection;
  nativeBuildInputs = [ cmake ];
}
