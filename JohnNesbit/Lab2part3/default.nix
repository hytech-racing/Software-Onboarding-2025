{ stdenv, cmake, hellolib }:

stdenv.mkDerivation rec {
  pname = "helloapp";
  version = "0.1.0";
  src = ./helloapp;
  nativeBuildInputs = [ cmake hellolib ];
    
  cmakeFlags = [ "-DCMAKE_INSTALL_PREFIX=$out" ];
  
  installPhase = ''
    mkdir -p $out/bin
    cp HelloWorldEx $out/bin/
  '';

  meta = {
    description = "A sample library";
  };
}
