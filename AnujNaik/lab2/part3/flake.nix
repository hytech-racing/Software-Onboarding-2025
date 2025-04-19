{
  description = "Hello world lab 2 part 3 flake";
  #links to other flakes or other pkg repo
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    hellolib.url = "github:AnujNaik/HyTech-Lab2-Part3-Lib";
  };
  
  outputs = { self, nixpkgs, utils, hellolib}:
    # let in used to declare variables syntax: ${variable}
    let
      # A derivation is an instruction that Nix uses to realise a Nix package.
      

      #target_overlay = final: prev: rec { 
      target_overlay = final: prev: { 
        target = final.callPackage ./default.nix { };
      };

      my_overlays = [ target_overlay hellolib.overlays.default];

      #correct pkgs for the corresponding system
      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default hellolib.overlays.default ];
      };
    in
    {
      #this is for nix build  
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.aarch64-darwin.default = pkgs.target;

      #for the dev shell -nix develop
      # devShells.aarch64-darwin.default =
      #   pkgs.mkShell rec {
      #     # Update the name to something that suites your project.
      #     name = "anuj's main";
      #     packages = with pkgs; [
      #       # Development Tools
      #       cmake
      #       target
      #     ];

      #     # Setting up the environment variables you need during
      #     # development.
      #     shellHook =
      #       let
      #         icon = "f121";
      #       in
      #       ''
      #         echo "hello mom"
      #         export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
      #       '';
      #   };

    };
}