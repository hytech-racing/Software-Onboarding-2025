{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_world";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}
