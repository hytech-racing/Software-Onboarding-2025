{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "lab2_p1_cmake";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}
