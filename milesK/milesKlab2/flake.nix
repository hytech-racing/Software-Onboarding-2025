{
    description = "Hello";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };
    outputs = {self, nixpkgs}:
    let
        hello_lib_overlay = final: prev: {
            hello_lib = final.callPackage ./default.nix { };
        };
        my_overlays = [ hello_lib_overlay ];
        pkgs = import nixpkgs {
            system = "x86_64-linux";
            overlays = [ self.overlays.default ];
        };
    in 

#        {
#            overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
#
#            packages.x86_64-linux =
#            rec {
#                hello_lib = pkgs.hello_lib;
#                default = hello_lib;
#            };
#        };
    {
        packages.x86_64-linux.default = pkgs.hello_lib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
