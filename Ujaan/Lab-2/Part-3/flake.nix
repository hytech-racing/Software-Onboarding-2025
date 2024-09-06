{
  description = "part 2 flake";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    hello_lib.url = "github:KingSyclone/nix-hello-lib";
  };

  outputs = { self, nixpkgs, utils, hello_lib }:
  let
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ hello_lib.overlays.default ];
    };

   in {
    packages.x86_64-linux.default = pkgs.callPackage ./default.nix {
    };

    devShells.x86_64-linux.default = pkgs.mkShell rec {
      name = "nix-devshell";
      packages = with pkgs; [
        cmake
        hello_app
        hello_lib.packages."x86_64-linux".default
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
