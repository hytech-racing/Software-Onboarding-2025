
{ stdenv, cmake, hellolib }:

stdenv.mkDerivation {
  pname = "helloapp";
  version = "0.1.0";
  src = ./helloapp;

  nativeBuildInputs = [ cmake ]; 
  buildInputs = [ hellolib ];
  
}