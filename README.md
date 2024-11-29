# So Long

## Introduction

**So Long** is a fun and engaging project where you create a small 2D game using MiniLibX, the school's graphical library. The game revolves around navigating a character through a map to collect items and find an exit. This project was an exciting opportunity to dive into 2D graphics, window management, event handling, and more, all while honing C programming skills.

## Project Description

In this game, the player navigates a map filled with walls, collectibles, and an exit. Using keyboard inputs, the player moves the character to collect all items and reach the exit through the shortest possible route. The game displays movements in the terminal and provides clean and responsive graphic management.

### Key Features

1. **Basic Gameplay**:
   - Move the player character using `W`, `A`, `S`, `D` (or `Z`, `Q`, `S`, `D`).
   - Collect all items (`C`) and reach the exit (`E`) to win.
   - Movement is restricted by walls (`1`).
   - Movement count is displayed in the terminal.

2. **Graphical Features**:
   - 2D top-down or profile view.
   - Smooth window management: resizing, minimizing, and closing.
   - Window can be closed using `ESC` or the close button.

3. **Map Handling**:
   - The map is loaded from a `.ber` file.
   - Valid maps include:
     - Walls (`1`), empty spaces (`0`), collectibles (`C`), exit (`E`), and player start (`P`).
     - Exactly 1 player start and 1 exit.
     - Surrounded by walls, rectangular, and contain at least one collectible.
     - A valid path from the player to the exit, covering all collectibles.

### File Structure

- **Mandatory Files**:
  - Source files: `*.c`
  - Header files: `*.h`
  - Assets: `textures` (e.g., sprites for the game)
  - Maps: `.ber` files (map descriptions)
  - Makefile: Includes rules for `NAME`, `all`, `clean`, `fclean`, `re`.

### Example Map (.ber File)

```plaintext
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
