{
    description = "Hello";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
        hellolib.url = "github:mileskent/hellolib";
    };
    outputs = {self, nixpkgs, hellolib}:
    let
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default hellolib.overlays.default ];
    };  

    hellolib_overlay = final: prev: {
      hellolib = final.callPackage ./default.nix { };
    };
    my_overlays = [ hellolib_overlay ];
    in 

    {
        packages.x86_64-linux.default = pkgs.hellolib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
