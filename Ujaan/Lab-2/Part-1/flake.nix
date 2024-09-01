{
    description = "part 2 flake";
    let
      hello_lib_overlay = final: prev: {
        hello_lib = final.callPackage ./default.nix { };
      };
      my_overlays = [ hello_lib_overlay ];
      pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ];
      };
    in 
    {
     overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

      packages.x86_64-linux =
        rec {
          hello_lib = pkgs.hello_lib;
          default = hello_lib;
        };

      devShells.x86_64-linux.default =
        pkgs.mkShell rec {
          # Update the name to something that suites your project.
          name = "nix-devshell";
          packages = with pkgs; [
            # Development Tools
            cmake
            hello_lib
          ];

          # Setting up the environment variables you need during
          # development.
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
