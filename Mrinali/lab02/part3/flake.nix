{
  description = "part 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    hellolib.url = "git@github.com:happyCupcake/hellolib.git"
  };

  outputs = { self, nixpkgs }: 
    let 
    pkgs = import nixpkgs {
      system = "x86_64-darwin";
      overlays = [ self.overlays.default ];
    };  

    hellolib_overlay = final: prev: rec {
      helloapp = final.callPackage ./default.nix {};
    };

    my_overlays = [ hellolib_overlay ];
  
  in
  {      
    packages.x86_64-darwin.default = pkgs.helloapp;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}