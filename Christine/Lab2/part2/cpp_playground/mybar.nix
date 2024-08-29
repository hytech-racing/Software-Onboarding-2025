
{ stdenv, cmake}:

#make Derivation
stdenv.mkDerivation rec {
  pname = "mybar";
  version = "0.1.0";
  src = ./bar/.;

  #make install
  nativeBuildInputs = [ cmake ];  
 

}