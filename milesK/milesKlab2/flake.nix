{
    description = "Hello";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };
    outputs = {self, nixpkgs}:
    let
        hellolib_overlay = final: prev: {
            hellolib = final.callPackage ./default.nix { };
        };
        my_overlays = [ hellolib_overlay ];
        pkgs = import nixpkgs {
            system = "x86_64-linux";
            overlays = [ self.overlays.default ];
        };
    in 

    {
        packages.x86_64-linux = {
            hellolib = pkgs.hellolib;
            hellolib_exe = pkgs.callPackage ./hellolib_exe.nix { hellolib = pkgs.hellolib; };
        };

        packages.x86_64-linux.default = pkgs.hellolib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
