{
    description = "a nix flake to run Hello World with a Nix";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };

    outputs = { self, nixpkgs} :
        let
            hello_program_overlays = final: prev: {
                hello_lib = final.callPackage ./libraryDerivation.nix {};
                hello_executable = final.callPackage ./default.nix {};
            };

            overlays_to_install = [ hello_program_overlays ];

            pkgs = import nixpkgs {
                system = "aarch64-darwin";
                overlays = [self.overlays.default];
            };
        in {
            packages.aarch64-darwin.default = pkgs.hello_executable;
            overlays.default = nixpkgs.lib.composeManyExtensions overlays_to_install;
        };


}