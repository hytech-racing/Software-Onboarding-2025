# In this file, the input names do matter because they actually refer to the build nix packages. 
#In flake.nix you can name them whatever because you specify the url.
{ stdenv, cmake, hello_package }:

stdenv.mkDerivation rec {
  pname = "hello_executable";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ hello_package ];
}