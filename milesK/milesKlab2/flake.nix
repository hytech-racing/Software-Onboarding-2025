{
    description = "Hello";
    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    };
    outputs = {self, nixpkgs}:
    let
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = [ self.overlays.default ];
    };  

    hellolib_overlay = final: prev: {
      hellolib = final.callPackage ./hellolib.nix { };
      hellolib_exe = final.callPackage ./default.nix { };
    };
    my_overlays = [ hellolib_overlay ];
    in 

    {
        packages.x86_64-linux.default = pkgs.hellolib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };
}
