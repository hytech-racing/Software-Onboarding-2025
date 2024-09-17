{ stdenv, cmake, lab3app }:

stdenv.mkDerivation {
  pname = "lab3app";
  version = "0.1.0";
  src = ./.;

  nativeBuildInputs = [ cmake ]; 
  buildInputs = [ lab3app ];
  
}