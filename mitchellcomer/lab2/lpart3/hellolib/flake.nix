{
  description = "part 2 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
    let 
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };  

    hello_lib_overlay = final: prev: {
      hello_lib = final.callPackage ./default.nix { };
    };
    my_overlays = [ hello_lib_overlay ];

    
  in
  {      
    packages.x86_64-linux.default = pkgs.hello_lib;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}
