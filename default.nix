{ stdenv, cmake, HelloLibrary }:

stdenv.mkDerivation rec {
  pname = "helloapp";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake HelloLibrary ];
}
