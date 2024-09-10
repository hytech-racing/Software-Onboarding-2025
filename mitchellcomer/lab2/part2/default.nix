{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "hello_lib_exe";
  version = "0.1.0";
  src = ./hello_lib_exe;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}