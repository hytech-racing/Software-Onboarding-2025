{
    description = "Lab 2 Part 1 Flake"
    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };
    outputs = {self, nixpkgs}:
    let
        hello_lib_overlay = final: prev: {
            hello_lib = final.callPackage ./default.nix { };
            #This line defines hello_lib as the derivation from default.nix
            #Important stuff
        };
        my_overlays = [hello_lib_overlay];

        pkgs = import nixpkgs {
            system = "x86_64-linux";
            overlays = [self.overlays.default];
        };
    in {
        pachages.x86_64-linux.default = pkgs.hello_lib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}