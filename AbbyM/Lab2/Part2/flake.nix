{
    description = "lab 2 part 2 flake.nix";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };

    outputs = { self, nixpkgs} : 
        
        let 
            hello_world_overlay = final: prev: rec {
                hello_lib = final.callPackage ./hellolib.nix { };
                hello_world = final.callPackage ./default.nix { inherit hello_lib; };
            };

            my_overlays = [ hello_world_overlay ];

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
