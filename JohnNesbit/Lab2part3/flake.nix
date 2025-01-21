{
description = "part 1 flake";

inputs = {
nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
utils.url = "github:numtide/flake-utils";
hellolib.url = "github:JohnNesbit/HyTechRacingLab";
};

outputs = { self, nixpkgs, hellolib, utils }:
let
hello_app_overlay = final: prev: {
hello_app = final.callPackage ./default.nix { hellolib = hellolib.packages.x86_64-linux.default; };
};
my_overlays = [ hello_app_overlay];
pkgs = import nixpkgs {
system = "x86_64-linux";
overlays = [ self.overlays.default ];
extraPackages = hellolib.packages.x86_64-linux.default;
};
in
{
packages.x86_64-linux.helloapp = pkgs.hello_app;
packages.x86_64-linux.default = pkgs.hello_app;

overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
};
}