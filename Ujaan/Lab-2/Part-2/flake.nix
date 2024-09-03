{
  description = "part 2 flake";
   inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    
  };
  
  outputs = { self, nixpkgs, utils }:
  let
    hello_app_overlay = final: prev: rec {
      hello_lib = final.callPackage ./default.nix { };
      hello_app = final.callPackage ./yo.nix { 
          inherit hello_lib;
        };
    };
    


    my_overlays = [ hello_app_overlay ];

        pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ hello_app_overlay ];
    };

  in {
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-linux.default = pkgs.hello_app;
  

    devShells.x86_64-linux.default = pkgs.mkShell rec {
      name = "nix-devshell";
      packages = with pkgs; [
        cmake
        hello_app
      ];

      shellHook = let
        icon = "f121";
      in
      ''
        export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
      '';
    }; 
  };
}
