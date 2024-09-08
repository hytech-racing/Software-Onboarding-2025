
{ stdenv, cmake, hellolib }:

#make Derivation
stdenv.mkDerivation {
  pname = "helloapp";
  version = "0.1.0";
  src = ./helloapp;

  #make install
  nativeBuildInputs = [ cmake ]; 
  buildInputs = [ hellolib ];
  
}