workspace "C_Projects"
  architecture "x64"

  startproject "Tree"

  configurations {
    "Debug",
    "Release",
  }

-- Libraries
include "Terminal"

-- All platform
include "HelloWorld"
include "Tree"
include "TrafficLight"
include "HelloCircularQueue"
include "GuessTheNumber"
include "TestTerminal"

-- Platform specific projects

-- Exclude Windows
if os.host() ~= "windows" then
  include "HelloNCurses"
  include "TMatrix"
end