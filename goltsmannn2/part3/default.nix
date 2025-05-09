{ stdenv, cmake, protobuf}:

stdenv.mkDerivation rec {
    pname = "software_onboarding_lab_3_package";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [cmake];
    buildInputs = [ protobuf ];
}