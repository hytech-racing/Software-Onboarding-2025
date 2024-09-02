{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "lab2_part1";
  version = "0.1.0";
  src = "CMakeLists.txt";
  nativeBuildInputs = [ cmake ];
}