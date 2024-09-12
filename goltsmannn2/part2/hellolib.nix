{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "lab2_part2_library";
  version = "0.1.0";
  src = ./hellolib;
  nativeBuildInputs = [ cmake ];
}
