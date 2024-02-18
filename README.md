So_long :
=========

Project Description
-------------------

In this project, you will code a little 2D game with a character that will escape after consuming all the collectibles.

Project Requirements
--------------------

* The game uses the MiniLibX library.
* The game takes a map description file with the .ber extension as a parameter.
* Use the W, A, S, and D keys to move.
* Display the current number of movements in the shell.
* The characters cannot move into walls; collisions with walls should be detected and handled.
* The window management should be smooth, allowing easy switching, minimizing, and closing of the game window.
* Pressing the ESC key or clicking the redc cross should cleanly exit the game.

Map
---

The map is a rectangular grid represented by characters. It consists of the following elements:

* 0: Empty space
* 1: Wall
* C: Collectible
* E: Exit point
* P: Starting position of the dolphin
* **Map Exemple:**
    
    | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
    | --- | --- | --- | --- | --- | --- | --- |
    | 1   | **C** | 0   | **C** | 0   | 0   | 1   |
    | 1   | 0   | 1   | 0   | 0   | 0   | 1   |
    | 1   | **E** | 1   | 0   | 0   | **P** | 1   |
    | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
    

The map must be valid and meet the following criteria:

* It should contain at least one exit, one collectible, and one starting position for the dolphin.
* It must be rectangular and surrounded by walls.
* Any invalid map configuration should display an error message and exit the game.

Getting Started
---------------

1.  This project is an introduction to MLX, don't spend too much time on it as you will have the opportunity to code better games later.
2.  Begin with the parsing while creating an clean data structure to use later in the game.
3.  To make sure the game is fluid, code your own function to print the pixels.
4.  This is an older version of so_long so there is no backtracking needed to know if the game is possible.

Resources
---------

* [MLX Documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
