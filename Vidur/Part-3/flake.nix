{
    description = "part 1 flake";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        utils.url = "github:numtide/flake-utils";
        hellolib.url = "github:vidur2/vidur-lab2";
    };

    outputs = { self, nixpkgs, hellolib, utils }:
    let
    pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ hellolib.overlays.default ];
    };



    
    in
    {
        packages.aarch64-darwin.default = pkgs.callPackage ./default.nix {
        };
    };
}