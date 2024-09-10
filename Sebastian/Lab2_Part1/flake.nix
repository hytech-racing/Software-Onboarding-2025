{
  description = "part 1 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    hello_lib_overlay = final: prev: {
      hello_lib = final.callPackage ./default.nix { };
    };

    # Define overlays as a list
    my_overlays = [ hello_lib_overlay ];

    # Import nixpkgs with overlays applied
    pkgs = import nixpkgs {
      system = "x86_64-linux";
      overlays = my_overlays;
    };  
  in
  {      
    # Define the default package for x86_64-linux
    packages.x86_64-linux.default = pkgs.hello_lib;

    # Expose the overlays for reuse if necessary
    overlays.default = hello_lib_overlay;
  };
}
