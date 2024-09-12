{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "helloapp";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}