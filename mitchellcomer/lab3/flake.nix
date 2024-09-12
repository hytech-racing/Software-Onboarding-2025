{
  description = "lab 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }: 
  let 
    system = "x86_64-linux";

    lab3_overlay = final: prev: {
      lab3 = final.callPackage ./default.nix { };
    };
    my_overlays = [ lab3_overlay ];

    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };  
  in
  {      
    packages.x86_64-linux.default = pkgs.lab3;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    legacyPackages.x86_64-linux =
    import nixpkgs {
      inherit system;
      overlays = [
        (final: _: { lab3 = final.callPackage ./default.nix { }; })
      ];
    };
  };
}
