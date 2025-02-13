{
  description = "lab2 part 2";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    
  };
  
  outputs = { self, nixpkgs, utils }:
    let
      target_overlay = final: prev: rec { 
        hellolib = final.callPackage ./hellolib.nix { };

        target = final.callPackage ./default.nix { 
          inherit hellolib;
        };
      };

      my_overlays = [ target_overlay ];

      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        # system = "x86_64-darwin";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.aarch64-darwin.default = pkgs.target;
      # packages.x86_64-darwin.default = pkgs.target;

      devShells.aarch64-darwin.default =
      # devShells.x86_64-darwin.default =
        pkgs.mkShell rec {
          name = "joel's playground";
          packages = with pkgs; [
            cmake
            target
          ];

          shellHook =
            let
              icon = "f121";
            in
            ''
              echo "hello world"
              export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
            '';
        };

    };
}