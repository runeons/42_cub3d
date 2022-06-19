# 42 Cub3D

#### Overview
💙 First graphic project  
This is a 42 project whose aim it to code a dynamic view inside a maze, inspired by Wolf3D 90's game.
#### Introduced concepts
⭐ Graphic library  
⭐ Raycasting  
⭐ Image files reading  
⭐ Window management  
⭐ Event handling
 
#### Description
- Code a maze view from a first-person perspective that enables:
    - straight movement : <kbd>W</kbd>, <kbd>A</kbd>, <kbd>S</kbd>, <kbd>D</kbd>
    - rotation : <kbd>⟵</kbd> and <kbd>⟶</kbd>
    - exit : <kbd>ESC</kbd>
- Read map file, that can set up:
    - R  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: resolution   
    - NO/SO/WE/EA &nbsp;&nbsp;: textures for walls
    - S &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: texture for sprites
    - C/F &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: ceiling/floor colors
    - maze map&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 0 = empty, 1 = wall, 2 = sprite, N/S/W/E = player initial position
#### Map example
![map_example](https://user-images.githubusercontent.com/49759654/174478312-7be881c6-a219-4891-960e-4c260a8bae4c.jpg)

#### Restrictions
- Minilibx
#### Usage
    make && ./cub3d /maps/first.cub 
(or any .cub file in the maps folder)
