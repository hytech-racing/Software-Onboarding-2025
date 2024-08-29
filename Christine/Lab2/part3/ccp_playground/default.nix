
{ stdenv, cmake, mybar }:

#make Derivation example
stdenv.mkDerivation {
  pname = "target";
  version = "0.1.0";
  src = ./.;

  #calls make install
  nativeBuildInputs = [ cmake ]; 

  #other inputs you want while building this derivation
  buildInputs = [mybar];

} 