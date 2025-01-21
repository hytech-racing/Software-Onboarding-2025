{
description = "part 1 flake";

inputs = {
nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
};

outputs = { self, nixpkgs }:
let
telemetry_lib_overlay = final: prev: {
telemetry_lib = final.callPackage ./telemetryLib/default.nix { protobuf = final.protobuf; };
};
server_lib_overlay = final: prev: {
server_lib = final.callPackage ./serverLib/default.nix {  telemetryLib = final.telemetry_lib; protobuf = final.protobuf;};
};
server_app_overlay = final: prev: {
server_app = final.callPackage ./serverApp/default.nix { telemetryLib = final.telemetry_lib; serverLib = final.server_lib; protobuf = final.protobuf;};
};
my_overlays = [ server_lib_overlay telemetry_lib_overlay server_app_overlay];
pkgs = import nixpkgs {
system = "x86_64-linux";
overlays = [ self.overlays.default ];
};
in
{
packages.x86_64-linux.serverLib = pkgs.server_lib;
packages.x86_64-linux.telemetryLib = pkgs.telemetry_lib;
packages.x86_64-linux.serverApp = pkgs.server_app;
packages.x86_64-linux.default = pkgs.server_app;


overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
};
}