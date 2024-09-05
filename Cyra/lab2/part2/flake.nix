{
  description = "Test Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {
     let
      hello_app_overlay = final: prev: rec {
      hello_lib = final.callPackage ./default.nix { };
      hello_app = final.callPackage ./random.nix { 
          inherit hello_lib;
        };
      };
    


    my_overlays = [ hello_app_overlay ];

      pkgs = import nixpkgs {
      system = "aarch64-darwin";
      overlays = [ hello_app_overlay ];
    };

      in
      {
        hello = pkgs.hello;
        default = pkgs.callPackage ./default.nix {};
      };
    };
  };
