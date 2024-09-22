{
  description = "Lab 3 Flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }: 
  let
    system = "x86_64-linux";

    lab3_overlay = final: prev: rec {
      protoMessage = final.callPackage ./default.nix { };
    };
    my_overlays = [ lab3_overlay ];

    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };
    in
    {
      packages.x86_64-linux.default = pkgs.protoMessage;
      overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;

      legacyPackages.x86_64-linux =
        import nixpkgs {
          inherit system;
          overlays = [
            (final: _: { protoMessage = final.callPackage ./default.nix { }; })
          ];
      };
    };
}
