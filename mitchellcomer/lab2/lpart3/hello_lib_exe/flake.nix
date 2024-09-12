{
  description = "part 2 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    hellolib.url = "github:Comerm28/hellolib";
  };

  outputs = { self, nixpkgs, hellolib }: 
    let 
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default hellolib.overlays.default ];
    };  

    hello_lib_overlay = final: prev: rec {
      hello_lib_exe = final.callPackage ./default.nix { };
    };
    my_overlays = [ hello_lib_overlay ];

    
  in
  {      
    packages.x86_64-linux.default = pkgs.hello_lib;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}
