# C Project collection

Contains small project for C.

## Requirements
 - [premake5](https://github.com/premake/premake-core)

## How to use

```shell
git clone https://github.com/KTheXIII/C_Projects.git
```

```shell
cd C_Projects
```

```shell
premake5 <action>
```

`<action>`: Run `premake5 --help` for more actions. Example: `gmake2` for generating Makefile.

## How to create new project

1. Copy the `HelloWorld` project and change the name.

2. Edit the premake5.lua in the your newly created project and change the project name to the same name as the directory.

3. Edit the root premake5.lua file look at how the HelloWorld project is included. Add you project in the next line with your project name.

Sample

```lua
include "HelloWorld"
include "Tree"
```