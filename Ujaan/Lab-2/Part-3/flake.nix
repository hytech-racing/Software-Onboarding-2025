{
  description = "part 2 flake";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    hello_lib.url = "github:KingSyclone/nix-hello-lib";
  };

  outputs = { self, nixpkgs, utils, hello_lib }:
  let
    hello_app_overlay = final: prev: rec {
      hello_app = final.callPackage ./default.nix {
        hello_lib = hello_lib.packages."x86_64-linux".default;
      };
    };

    my_overlays = [ hello_app_overlay ];

    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = my_overlays;
    };

  in {
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    packages.x86_64-linux.default = pkgs.hello_app;

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
