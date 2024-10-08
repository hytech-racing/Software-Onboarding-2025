{
  description = "part 1 flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
  };


  outputs = { self, nixpkgs }:
  let
    hello_lib_overlay = final: prev: {
        hello_lib = final.callPackage ./default.nix { };
    };
    my_overlays = [hello_lib_overlay];
    pkgs = import nixpkgs {
      system = "aarch64-darwin";
      overlays = [ self.overlays.default ];
    };
    in
    {      
    packages.aarch64-darwin.default = pkgs.hello_lib;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}

  