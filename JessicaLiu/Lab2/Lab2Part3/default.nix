{ stdenv, cmake, helloworld_lib }:

stdenv.mkDerivation rec {
  pname = "helloworld";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ helloworld_lib ];
}