workspace "C_Projects"
  architecture "x64"

  startproject "Tree"

  configurations {
    "Debug",
    "Release",
  }

include "HelloWorld"
include "Tree"