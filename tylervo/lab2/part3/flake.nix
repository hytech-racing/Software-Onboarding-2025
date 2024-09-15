{
  description = "tyler's flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    hellolib.url = "github:tylerdvo/hellolib2";
  };

  outputs = { self, nixpkgs, hellolib }:
    let
      hello_overlay = final: prev: rec {
        hello = final.callPackage ./default.nix { };
      };

      my_overlays = [ hello_overlay ];

      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default hellolib.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.aarch64-darwin.default = pkgs.hello;
    };
}