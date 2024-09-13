{ stdenv, cmake  }:

stdenv.mkDerivation rec {
    pname = "helloapp";
    version = "1.0.0";
    src = ./.; # Path to your source directory

    nativeBuildInputs = [ cmake ];
}