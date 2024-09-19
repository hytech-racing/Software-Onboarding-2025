{
    description = "Flake part 1";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs";
        nixutils.url = "github:numtide/flake-utils";
        easy_cmake.url = "github:RCMast3r/easy_cmake";
    };
    outputs = {
        self, nixpkgs, nixutils, easy_cmake
    }:
    let
      hello_lib_overlay = final: prev: {
        hello_lib = final.callPackage ./default.nix { };
      };
      my_overlays = [ hello_lib_overlay ];
      pkgs = import nixpkgs {
        system = "aarch64-darwin";
        overlays = [ self.overlays.default ];
      };
    in 
    {
     overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

      packages.aarch64-darwin =
        rec {
          hello_lib = pkgs.hello_lib;
          default = hello_lib;
        };

      devShells.aarch64-darwin.default =
        pkgs.mkShell rec {
          name = "nix-devshell";
          packages = with pkgs; [
            cmake
            hello_lib
          ];

          
          shellHook =
            let
              icon = "f121";
            in
            ''
              export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
            '';
        }; 
    };
}
