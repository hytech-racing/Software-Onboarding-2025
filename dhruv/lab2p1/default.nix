{stdenv, cmake}:
#instructions on how to build the nix package
stdenv.mkDerivation rec {
    pname = "HelloLib";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
}