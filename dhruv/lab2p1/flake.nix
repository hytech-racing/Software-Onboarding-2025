{
    description = "flakep1";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    };

    outputs = {self, nixpkgs}:

    let
        HelloLib_overlay = final: prev: { #Overlays in Nix are functions that accept two arguments (usually called final and prev) and return a set of packages
            HelloLib = final.callPackage ./default.nix {}; #this makes "HelloLib" a package or sets it as a package here?
        };

    my_overlays = [ HelloLib_overlay ]; #so this is where I would add multiple overlays if needed
                                        #HelloLib_overlay returns packages?

    pkgs = import nixpkgs {
        system = "x86_64-linux";
        overlays = [ self.overlays.default ]; #are the self.overlays what I set earlier?
    };

    in
    {
        packages.x86_64-linux.default = pkgs.HelloLib;
        overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
    };

}