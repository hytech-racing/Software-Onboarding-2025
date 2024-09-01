{
  description = "Server-client application";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    let
    
      program_overlay = final: prev: rec { 
        program = final.callPackage ./default.nix { 
        };
      };

      my_overlays = [ program_overlay ];
      pkgs = import nixpkgs {
        system = "x86_64-darwin";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-darwin.default = pkgs.program;

      devShells.x86_64-darwin.default =
        pkgs.mkShell rec {
          name = "client-server";
          packages = with pkgs; [
            cmake
            protobuf
            program
          ];

          shellHook =
            let
              icon = "f121";
            in
            ''
              echo "hello MOMMMM"
              export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
            '';
        };

    };
}