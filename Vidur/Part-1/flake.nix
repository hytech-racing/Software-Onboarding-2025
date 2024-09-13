{
    description = "part 1 flake";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };
    outputs = { self, nixpkgs }:
    let
    hellolib_overlay = final: prev: {
        hellolib = final.callPackage ./default.nix { };
    };
    my_overlays = [ hellolib_overlay ];


    pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default ];
    };
    in
    {
        packages.x86_64-linux.default = pkgs.hellolib;
        packages.aarch64-darwin.default = pkgs.hellolib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}