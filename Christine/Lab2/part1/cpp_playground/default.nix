
{ stdenv, cmake }:

#make Derivation
stdenv.mkDerivation rec {
  pname = "target";
  version = "0.1.0";
  src = ./.;

  #make install
  nativeBuildInputs = [ cmake ];  
}