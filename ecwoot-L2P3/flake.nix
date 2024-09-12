{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
    hellolib.url = "github:ecwoot/nixhellolib";
  };

  outputs = { self, nixpkgs, utils, hellolib }:
  let
    hellolib_overlay = final: prev: {
      hellolib = final.callPackage ./hellolib.nix{};
      helloapp = final.callPackage ./default.nix{};
    };
    my_overlays = [ hellolib_overlay ];


    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default hellolib.overlays.default ];
    };
  in
  {
    packages.x86_64-linux.default = pkgs.helloapp;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}
