{
  description = "lab2p3 flake2";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    hellolib.url = "github:dhruvgowda987/hellolibgit";
  };

  outputs = { self, nixpkgs, hellolib }: 
    let 
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default hellolib.overlays.default ];
    };  

    hellolib_overlay = final: prev: {
      hellolib_exe = final.callPackage ./default.nix { };
    };
    my_overlays = [ hellolib_overlay ];

    
  in
  {      
    packages.x86_64-linux.default = pkgs.hellolib;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}