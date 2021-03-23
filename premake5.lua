workspace "C_Projects"
  architecture "x64"

  startproject "Tree"

  configurations {
    "Debug",
    "Release",
  }

-- All platform
include "HelloWorld"
include "Tree"
include "TrafficLight"
include "HelloCircularQueue"
include "GuessTheNumber"

-- Platform specific projects

-- Exclude Windows
if os.host() ~= "windows" then
  include "HelloNCurses"
  include "TMatrix"
end