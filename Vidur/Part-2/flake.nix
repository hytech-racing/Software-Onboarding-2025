{
    description = "part 1 flake";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };
    outputs = { self, nixpkgs }:
    let
    helloapp_overlay = final: prev: rec {
        hellolib = final.callPackage ./hellolib.nix { };
        helloapp = final.callPackage ./default.nix { inherit hellolib; };
    };
    my_overlays = [ helloapp_overlay ];


    pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ helloapp_overlay ];
    };
    in
    {
        packages.aarch64-darwin.default = pkgs.helloapp;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}