# Here we are just calling a function to build our CMake

{ stdenv, cmake }: 

stdenv.mkDerivation {
    pname = "library_derivation";
    version = "1.0";
    src = ./library;
    buildInputs = [ cmake ];
}

# mkDerivation is a function within stdenv: https://blog.ielliott.io/nix-docs/mkDerivation.html
# "rec" allows for recursive references within a set: https://nix.dev/tutorials/nix-language.html (ctrl-f)