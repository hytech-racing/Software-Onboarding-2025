{
  description = "Lab 3 flake";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
    nixutils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self, nixpkgs, nixutils
  }:
  
  let hello_world_overlay = final: prev: {
    hello_world = final.callPackage ./default.nix { };
  };

  my_overlays = [ hello_world_overlay ];
  pkgs = import nixpkgs {
    system = "aarch64-darwin";
    overlays = [ self.overlays.default ];
  };

  in {
    overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

    packages.aarch64-darwin =
      rec {
        hello_world = pkgs.hello_world;
        default = hello_world;
      };

    devShells.aarch64-darwin.default =
      pkgs.mkShell rec {
        name = "nix-devshell";
        packages = with pkgs; [
          cmake
          hello_world
        ];
        shellHook = ''
          export PS1="$(echo -e '\uF121') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
        '';
      };
  };
}
