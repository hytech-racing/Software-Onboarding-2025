{
  description = "part 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    hello.url = "github:dnguyen-hub/learning";
  };

  outputs = { self, nixpkgs, hello }: 
    let 
    pkgs = import nixpkgs {
      system = "aarch64-darwin";
      overlays = [ self.overlays.default hello.overlays.default ];
    };  

    hello_lib_overlay = final: prev: rec {
      hello_lib = final.callPackage ./default.nix { };
    };
    my_overlays = [ hello_lib_overlay ];

    
  in
  {      
    packages.aarch64-darwin.default = pkgs.hello;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}
