{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";
  };


  outputs = {self, nixpkgs}: 
    let
      pkgs = import nixpkgs {
        system = "aarch64-darwin";
      };
      hello = pkgs.callPackage ./default.nix {};
    in {
      packages.aarch64-darwin = {
        default = hello;
      };
    };
}
