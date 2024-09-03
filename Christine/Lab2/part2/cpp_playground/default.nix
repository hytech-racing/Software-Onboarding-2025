
{ stdenv, cmake, mybar }:

#make Derivation
stdenv.mkDerivation {
  pname = "target";
  version = "0.1.0";
  src = ./.;

  #make install
  nativeBuildInputs = [ cmake ]; 
  buildInputs = [ mybar ];
  
}