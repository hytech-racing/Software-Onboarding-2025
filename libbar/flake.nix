{
  description = "A very basic flake";

  inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        utils.url = "github:numtide/flake-utils";
      };

  outputs = { self, nixpkgs, utils }: 
    let 
      libbar_overlay = final: prev: rec {
        mybar = final.callPackage ./default.nix { };
      };

      my_overlays = [ libbar_overlay];

      pkgs = import nixpkgs {
        system = "x86_64-darwin";
        overlays = [ self.overlays.default ];
      };
    in 
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-darwin.default = pkgs.mybar;
      
      devShells.x86_64-darwin.default =
        pkgs.mkShell rec {
          # Update the name to something that suites your project.
          name = "christine's library";
          packages = with pkgs; [
            # Development Tools
            cmake
            mybar
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