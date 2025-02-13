{ stdenv, cmake}:

#make Derivation
stdenv.mkDerivation rec {
  pname = "hellolib";
  version = "0.1.0";
  src = ./hellolib;

  #make install
  nativeBuildInputs = [ cmake ];  
 

}