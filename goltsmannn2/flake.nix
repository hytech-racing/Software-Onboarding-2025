{
  description = "a set of macros to make cmake easier";


  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs = { self, nixpkgs, ... } @inputs:
      let
            system = "aarch64-darwin";
            pkgs = import nixpkgs {
                system = system;
            };
            hello_world_pkg = pkgs.callPackage ./default.nix {};
      in
      {
        packages.aarch64-darwin = rec {
            default = hello_world_pkg;
        };
      };

}
