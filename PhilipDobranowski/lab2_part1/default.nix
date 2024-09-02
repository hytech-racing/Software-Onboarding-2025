{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hello_world_lib";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
}