{ stdenv, cmake, protobuf}:

stdenv.mkDerivation rec {
  pname = "telemetryLib";
  version = "0.1.0";
  src = ./.;
  nativeBuildInputs = [ cmake protobuf ];
  
  cmakeFlags = [ "-DCMAKE_INSTALL_PREFIX=$out" ];
  
    # Ensure protobuf's include directory is found during compilation
  buildPhase = ''
    mkdir -p $out/include
	cp $src/telemetry.pb.h $out/include
    cmake . -DCMAKE_INSTALL_PREFIX=$out
    cmake --build .
	
  '';
  
    installPhase = ''
    make install
	'';

  

  meta = {
    description = "telemetry protobuf library";
  };
  
}
