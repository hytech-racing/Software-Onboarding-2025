{stdenv, cmake}:

stdenv.mkDerivation rec {
    pname = "test";
    version = "1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];

    buildPhase = ''
        cmake .
        make
    '';

    installPhase = ''
        make install
    ''; 

}