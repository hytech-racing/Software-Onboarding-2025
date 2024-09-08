{
    description = "Lab 3 Flake";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };
    outputs = {self, nixpkgs}:
    let
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };  

    {
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
