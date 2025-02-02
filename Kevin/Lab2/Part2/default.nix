# Here we are just calling a function to build our CMake

{ stdenv, cmake, hello_lib }: 

stdenv.mkDerivation {
    pname = "Hello World with Nix";
    version = "1.0";
    src = ./executable;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ hello_lib ];
}

# mkDerivation is a function within stdenv: https://blog.ielliott.io/nix-docs/mkDerivation.html
# "rec" allows for recursive references within a set: https://nix.dev/tutorials/nix-language.html (ctrl-f)