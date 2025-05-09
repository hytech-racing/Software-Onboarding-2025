{
  description = "lab 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }: 
  let 
    system = "aarch64-darwin";

    lab3_overlay = final: prev: {
      lab3 = final.callPackage ./default.nix { };
    };
    my_overlays = [ lab3_overlay ];

    pkgs = import nixpkgs {
      system = "aarch64-darwin";
      overlays = [ self.overlays.default ];
    };  
  in
  {      
    packages.aarch64-darwin.default = pkgs.lab3;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    legacyPackages.aarch64-darwin =
    import nixpkgs {
      inherit system;
      overlays = [
        (final: _: { lab3 = final.callPackage ./default.nix { }; })
      ];
    };
  };
}
