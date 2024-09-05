{
  description = "HyTech Software Onboarding 2025";

  # Pull nix code from the net/local to do things that are wanted. Basically a dependency.
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  #nixpkgs - path to local nixpkgs store
  #self - current flake, nixpkgs - flake imported from inputs

  outputs = { self, nixpkgs, ...} @ inputs:
      let
        supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];
        supportedPackages = function: nixpkgs.lib.genAttrs supportedSystems (system: function nixpkgs.legacyPackages.${system});
      in {
        packages = supportedPackages (pkgs: {
          default = pkgs.callPackage ./default.nix {};
        });
      };
}
