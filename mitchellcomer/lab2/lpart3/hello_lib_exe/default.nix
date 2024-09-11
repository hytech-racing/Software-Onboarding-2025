{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "hello_lib_exe";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}