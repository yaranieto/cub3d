*This project has been created as part of the 42 curriculum by ynieto-s and jnovoa-a.*

## Description

cub3D is a first-person 3D maze renderer inspired by Wolfenstein 3D, built with ray-casting and miniLibX.

This repository is a **team project** split into two main parts:

| Part | Owner | Status |
|------|-------|--------|
| Parsing & validation | yaranieto | Done |
| Ray-casting & rendering | partner | In progress |

### Parsing & validation

This layer is **complete for the mandatory subject requirements**. It includes:

- Reading `.cub` scene files line by line (Get Next Line, no global variables)
- Parsing texture identifiers and paths (`NO`, `SO`, `WE`, `EA`)
- Parsing floor and ceiling colors (`F`, `C`) with RGB validation (0–255)
- Parsing the map as it appears in the file, including **irregular row lengths** and internal spaces
- Validating scene configuration: all textures, both colors, exactly one player, non-empty map
- Validating that the map is **closed** (flood-fill from outside)
- Rejecting invalid characters, duplicate config entries, config after the map, and empty lines inside the map
- Initializing player position and view direction (`N` / `S` / `E` / `W`) for the renderer
- Clean error handling: prints `Error\n` + message and frees all allocated memory on failure

**Source files for this part:**

```
src/parse/       parse.c, parse_line.c, parse_textures.c, parse_colors.c
src/map/         map.c, map_load.c, map_validate.c, map_floodfill.c
src/scene/       scene.c, color.c
src/player/      player_init.c
src/utils/       utils.c
gnl/             get_next_line.c
```

The validated scene is stored in `t_scene` (`inc/cub3d.h`) and is ready to be consumed by the renderer.

### Ray-casting & rendering (partner — not yet implemented)

This part still needs to be built on top of the parsed scene:

- miniLibX window and image setup
- Loading `.xpm` textures from the paths stored in `t_scene`
- Ray-casting loop (DDA) and wall rendering with N/S/E/W textures
- Floor and ceiling color filling
- Keyboard input: `W` / `A` / `S` / `D`, arrow keys, `ESC`
- Window close on red cross; clean shutdown
- Game loop and smooth window behaviour

**Current behaviour:** `./cub3D map.cub` parses and validates the scene, then exits. The window and 3D view are not shown yet.

### Project progress estimate

| Area | Approx. share of mandatory work |
|------|--------------------------------|
| Parsing & validation | ~40–45% |
| Ray-casting & rendering | ~55–60% |

So it is **roughly half and half**, but the rendering side is slightly larger because it includes MLX, the game loop, input, and all drawing logic.

## Instructions

### Requirements

- GCC
- Make
- X11 development libraries (Linux)
- miniLibX (included in this repository for Linux)

### Compilation

```bash
make
```

Other Makefile targets:

```bash
make clean    # remove object files
make fclean   # remove object files and executable
make re       # rebuild from scratch
make norm     # run norminette on project sources
make bonus    # bonus features (not implemented yet; required Makefile target)
```

The `bonus` target exists because the 42 subject requires these Makefile rules: `all`, `clean`, `fclean`, `re`, and `bonus`. Right now it is a placeholder that prints a message; your partner (or both of you) will wire it up if you implement bonus features (minimap, mouse look, doors, etc.).

### Execution

The program takes exactly one scene file with a `.cub` extension:

```bash
./cub3D maps/min.cub
```

On invalid input or scene configuration, the program prints `Error\n` followed by an explicit message and exits cleanly.

### Scene file format

Each `.cub` file may contain texture paths, floor/ceiling colors, and a map. The map must be the last section and may include spaces. Valid map characters are `0`, `1`, `N`, `S`, `E`, and `W`.

Example:

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
111111
100N01
111111
```

## Resources

- [42 cub3D subject](https://github.com/qpeela/42_docs/blob/master/cub3d/cub3d.pdf)
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Doom source code notes on raycasting](https://github.com/id-Software/DOOM)
