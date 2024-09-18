{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "hellolib_exe";
  version = "0.1.0";
  src = ./hellolib_exe;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}
