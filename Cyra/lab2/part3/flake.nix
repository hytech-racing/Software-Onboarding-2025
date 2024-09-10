{
  description = "flake part 2";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    hello_lib.url = "github:skyraal/nixlab2";
    
  };
  
  outputs = { self, nixpkgs, utils }:
  let
    pkgs = import nixpkgs {
    system = "aarch64-darwin";
  };

  in {
    packages.aarch64-darwin.default = pkgs.hello_app;
    devShells.aarch64-darwin.default = pkgs.mkShell rec {
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
