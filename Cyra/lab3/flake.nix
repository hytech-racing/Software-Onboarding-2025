{
  description = "flake lab 3";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs }:
  let
    system = "aarch64-darwin";
    pkgs = import nixpkgs {
      overlays = [
        (final: _: { lab3 = final.callPackage ./default.nix { }; })
      ];
    };
  in rec {
      packages.${system}.default = pkgs.lab3;
      # defaultPackage.${system} = legacyPackages.mkShell {
      # nativeBuildInputs = [ legacyPackages.cmake ];
      # buildInputs = [ legacyPackages.protobuf legacyPackages.gcc ];
    };

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

    # legacyPackages.${system} = legacyPackages;
  

}