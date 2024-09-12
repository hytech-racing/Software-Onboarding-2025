{
  description = "part 3 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    hellolib.url = "github:BANANAPEEL202/hytech-onboarding-2025";
  };

  outputs = { self, nixpkgs, hellolib }: 
    let 
    pkgs = import nixpkgs {
      system = "aarch64-darwin";
      overlays = [ self.overlays.default hellolib.overlays.default ];
    };  

    hello_lib_overlay = final: prev: rec {
      hello_lib_exe = final.callPackage ./default.nix { };
    };
    my_overlays = [ hello_lib_overlay ];
  in
  {      
    packages.aarch64-darwin.default = pkgs.hello_world;
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
  };
}