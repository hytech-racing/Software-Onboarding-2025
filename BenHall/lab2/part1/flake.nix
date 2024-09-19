{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";
  };

  outputs = { self, nixpkgs, ... }:
    let
      hello_overlay = final: prev: {
        hello = final.callPackage ./default.nix { };
      };
      my_overlays = [ hello_overlay ];
      pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ];
      };
    in
    {
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
      packages.x86_64-linux =
        rec {
          hello = pkgs.hello;
          
          default = hello;
        };
    };

}
