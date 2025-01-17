{
    description = "a nix flake to run Hello World with a Nix";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };

    outputs = { self, nixpkgs} : {
        packages.aarch64-darwin = callPackage ./default.nix {};
    }

}