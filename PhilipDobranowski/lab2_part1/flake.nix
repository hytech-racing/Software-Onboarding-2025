{
  description = "Hello World part 1 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      pkgs = import nixpkgs {
        system = "x86_64-linux";
      };
      hello_world_lib_pkg = pkgs.callPackage ./default.nix { };
    in
    {
      packages.x86_64-linux = rec {
        hello_world_lib = hello_world_lib_pkg;
        default = hello_world_lib;
      };
    };
}