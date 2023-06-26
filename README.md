<!DOCTYPE html>
<html>
<body>
  <h1>So_long : <a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cljbd5ceo007308mltneinai5/project/2264467" alt="hlevi's 42 so_long Score" /></a></h1>
  
  <h2>Project Description</h2>
  <p>
    In this project, you will code a little 2D game with a character that will escape after consuming all the collectibles. 
  </p>
  
  <h2>Project Requirements</h2>
  <ul>
    <li>The game uses the MiniLibX library.</li>
    <li>The game takes a map description file with the .ber extension as a parameter.</li>
    <li>Use the W, A, S, and D keys to move.</li>
    <li>Display the current number of movements in the shell.</li>
    <li>The characters cannot move into walls; collisions with walls should be detected and handled.</li>
    <li>The window management should be smooth, allowing easy switching, minimizing, and closing of the game window.</li>
    <li>Pressing the ESC key or clicking the redc cross should cleanly exit the game.</li>
  </ul>
  
  <h2>Map</h2>
  <p>
    The map is a rectangular grid represented by characters. It consists of the following elements:
  </p>
  <ul>
    <li>0: Empty space</li>
    <li>1: Wall</li>
    <li>C: Collectible</li>
    <li>E: Exit point</li>
    <li>P: Starting position of the dolphin</li>
     <li>
      <strong>Map Exemple:</strong>
    <table>
      <tr><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td></tr>
      <tr><td>1</td><td><strong>C<strong></td><td>0</td><td><strong>C<strong></td><td>0</td><td>0</td><td>1</td></tr>
      <tr><td>1</td><td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>1</td></tr>
      <tr><td>1</td><td><strong>E<strong></td><td>1</td><td>0</td><td>0</td><td><strong>P<strong></td><td>1</td></tr>
      <tr><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td></tr>
    </table>
    </li>
  </ul>
  <p>
    The map must be valid and meet the following criteria:
  </p>
  <ul>
    <li>It should contain at least one exit, one collectible, and one starting position for the dolphin.</li>
    <li>It must be rectangular and surrounded by walls.</li>
    <li>Any invalid map configuration should display an error message and exit the game.</li>
  </ul>
  
 <h2>Getting Started</h2>
  <ol>
    <li>This project is an introduction to MLX, don't spend too much time on it as you will have the opportunity to code better games later.</li>
    <li>Begin with the parsing while creating an clean data structure to use later in the game.</li>
    <li>To make sure the game is fluid, code your own function to print the pixels.</li>
    <li>This is an older version of so_long so there is no backtracking needed to know if the game is possible.</li>
  </ol>
  <h2>Resources</h2>
  <ul>
    <li><a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html">MLX Documentation</a></li>
</body>
</html>
