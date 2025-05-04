{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "Lab 2 Part 1";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}