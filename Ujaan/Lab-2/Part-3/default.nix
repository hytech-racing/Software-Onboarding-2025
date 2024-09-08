{ stdenv, cmake, hello_lib }:

stdenv.mkDerivation {
  pname = "hello_app";
  version = "0.1.0";

  src = ./.;

  nativeBuildInputs = [ cmake hello_lib ];
  buildInputs = [ cmake hello_lib ];

}
