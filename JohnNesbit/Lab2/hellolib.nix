{ stdenv, cmake }:

stdenv.mkDerivation rec {
  pname = "hellolib";
  version = "0.1.0";
  src = ./hellolib;

  nativeBuildInputs = [ cmake ];

  buildPhase = ''
    cmake -S $src -B build -DCMAKE_INSTALL_PREFIX=$out
    cmake --build build
  '';

  installPhase = ''
    cmake --install build --prefix $out
  '';

  meta = {
    description = "A sample library";
    license = "MIT";
  };
}
