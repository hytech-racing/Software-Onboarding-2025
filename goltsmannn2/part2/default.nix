{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "lab2_part2_exec";
  version = "0.1.0";
  src = ./helloapp;
  nativeBuildInputs = [ cmake hellolib ];
}
