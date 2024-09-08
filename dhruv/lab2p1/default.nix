{stdenv, cmake}:
#instructions on how to build the nix package
stdenv.mkDerivation rec {
    pname = "HelloLib";
    version = "1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
}