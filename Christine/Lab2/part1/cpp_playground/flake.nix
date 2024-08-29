{
  description = "playground";
  #links to other flakes or other pkg repo
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
    
  };
  
  outputs = { self, nixpkgs, utils }:
    # let in used to declare variables syntax: ${variable}
    let
      # A derivation is an instruction that Nix uses to realise a Nix package.
      target_overlay = final: prev: {
        # pay attention to callPackage 
        target = final.callPackage ./default.nix { };
      };
      my_overlays = [ target_overlay ];

      #correct pkgs for the corresponding system
      pkgs = import nixpkgs {
        system = "x86_64-darwin";
        overlays = [ self.overlays.default ];
      };
    in
    {
      #this is for nix build  
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-darwin.default = pkgs.target;
    

      #for the dev shell -nix develop
      devShells.x86_64-darwin.default =
        pkgs.mkShell rec {
          # Update the name to something that suites your project.
          name = "christine's playground";
          packages = with pkgs; [
            # Development Tools
            cmake
            target
          ];

          # Setting up the environment variables you need during
          # development.
          shellHook =
            let
              icon = "f121";
            in
            ''
              echo "hello mom"
              export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
            '';
        };

    };
}