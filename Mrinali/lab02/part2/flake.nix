{
  description = "part 2 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
    let 
    pkgs = import nixpkgs {
      system = "x86_64-darwin";
      overlays = [ self.overlays.default ];
    };  

    hellolib_overlay = final: prev: rec {
      hellolib = final.callPackage ./hellolib.nix { };
      helloapp = final.callPackage ./default.nix { inherit hellolib; };
    };
    my_overlays = [ hellolib_overlay ];

    
  in
  {      
    packages.x86_64-darwin.default = pkgs.helloapp;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}