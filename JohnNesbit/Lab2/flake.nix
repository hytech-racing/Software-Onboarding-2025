{
description = "part 1 flake";

inputs = {
nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
};

outputs = { self, nixpkgs }:
let
hello_lib_overlay = final: prev: {
hello_lib = final.callPackage ./hellolib.nix { };
};
hello_app_overlay = final: prev: {
hello_app= final.callPackage ./default.nix { hellolib = final.hello_lib; };
};
my_overlays = [ hello_lib_overlay hello_app_overlay];
pkgs = import nixpkgs {
system = "x86_64-linux";
overlays = [ self.overlays.default ];
};
in
{
packages.x86_64-linux.hellolib = pkgs.hello_lib;
packages.x86_64-linux.helloapp = pkgs.hello_app;
packages.x86_64-linux.default = pkgs.hello_app;


overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
};
}