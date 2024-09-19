{
    description = "lab 2 flake.nix";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        utils.url = "github:numtide/flake-utils";
    };

    outputs = { self, nixpkgs, utils} : 
        
        let 
            hello_lib_overlay = final: prev: {
                hello_lib = final.callPackage ./default.nix {};
            };

            my_overlays = [ hello_lib_overlay ];

            pkgs = import nixpkgs {
                system = "x86_64-linux";
                overlays = [ self.overlays.default ];
            };

        in
        {
            packages.x86_64-linux.default = pkgs.hello_lib;
            overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
        };
    
}
