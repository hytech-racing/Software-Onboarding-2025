{ stdenv, cmake, serverLib, telemetryLib, protobuf }:

stdenv.mkDerivation rec {
  pname = "serverApp";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake serverLib telemetryLib protobuf];
    
  cmakeFlags = [ "-DCMAKE_INSTALL_PREFIX=$out" ];
  
  buildPhase = ''
    mkdir -p $out/bin
	cmake . -DCMAKE_INSTALL_PREFIX=$out
    cmake --build .
	
  '';

  # Install phase to move executables to $out/bin
  installPhase = ''
	make install
  '';

  meta = {
    description = "A sample library";
  };
}
