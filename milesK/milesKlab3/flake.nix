{
    description = "Lab 3 Flake";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        utils.url = "github:numtide/flake-utils";
    };
    outputs = {self, nixpkgs, utils}:
    let
        system = "x86_64-linux";
        legacyPackages.x86_64-linux =
        import nixpkgs {
            inherit system;
            overlays = [
                (final: _: { lab3 = final.callPackage ./default.nix { }; })
            ];
        };
    in
}
