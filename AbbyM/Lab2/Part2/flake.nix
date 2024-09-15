{
    description = "lab 2 part 2 flake.nix";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        utils.url = "github:numtide/flake-utils";
        hello_lib.url = "github:abbymartin/hytech_nix_onboarding";
    };

    outputs = { self, nixpkgs, utils, hello_lib } : 
        
        let 
            hello_world_overlay = final: prev: rec {
                hello_world = final.callPackage ./default.nix { };
            };

            my_overlays = [ hello_world_overlay hello_lib.overlays.default ];

            pkgs = import nixpkgs {
                system = "x86_64-linux";
                overlays = [ self.overlays.default ];
            };

        in
        {
            packages.x86_64-linux.default = pkgs.hello_world;
            overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
        };
    
}
