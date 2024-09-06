{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "hellobin";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}