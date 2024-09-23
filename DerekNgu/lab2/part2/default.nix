{ stdenv, cmake, hello}:


stdenv.mkDerivation  {
  pname = "hello_lib";
  version = "0.1.0";
  src = ./app;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hello ];
}