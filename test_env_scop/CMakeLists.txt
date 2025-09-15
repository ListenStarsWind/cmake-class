cmake_minimum_required(VERSION 3.18)

project(EnvVarDemo)

message("env: $ENV{OS}")

set(ENV{OS} "linux")

message("env: $ENV{OS}")