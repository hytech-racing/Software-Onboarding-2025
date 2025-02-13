{ stdenv, cmake, telemetryLib, protobuf}:

stdenv.mkDerivation rec {
  pname = "serverLib";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake telemetryLib protobuf ];
  
  cmakeFlags = [ "-DCMAKE_INSTALL_PREFIX=$out" ];

    buildPhase = ''
	mkdir -p $out/include
	cp $src/include/serverLib.h $out/include
    cmake -S $src -B build -DCMAKE_INSTALL_PREFIX=$out
    cmake --build build
  '';

  installPhase = ''
    cmake --install build --prefix $out
  '';
  
  meta = {
    description = "server library";
  };
  
}
