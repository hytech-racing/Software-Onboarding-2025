{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "main";
  version = "0.1.0";
  src = ./.;

  nativeBuildInputs = [ cmake ];
  buildInputs = [ hellolib ];
}

