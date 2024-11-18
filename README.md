
# Chess Knight Moves on a 5x5 Board

## Project Overview
This project implements a program to simulate the legal moves of a knight on a 5x5 chessboard. The program allows users to explore and manage possible knight movement paths using data structures designed to store board positions and movement paths. Additionally, the program determines whether it is possible for the knight to perform a complete tour of the board, starting from a given position, such that the knight visits every position on the board exactly once.
## File Structure
- **main.c**: The main file, handling input/output and core program logic.
- **Section1.h / section1.c**: Functions to calculate all possible knight moves from any position on a 5x5 board.
- **Section2.h / section2.c**: Implementations of linked list structures to store possible movement paths.
- **Section3.h / section3.c**: Tree structures representing possible knight paths on the board.
- **Section4.h / section4.c**: Functions to manage and insert data into linked lists for valid knight moves.

## System Requirements
- Standard C libraries like `stdio.h`, `stdlib.h`, and `stdbool.h`.

## Challenges and Insights
The project involves managing complex data structures and optimizing knight movement path calculations while adhering to the constraints of a 5x5 board.

## Examples
Here is an example of how to use the program:
input:
Starting position: A5
output:
   1  2  3  4  5
A|23|20|15|10| 1|

B|14| 9|22| 5|16|

C|21|24|19| 2|11|

D| 8|13| 4|17| 6|

E|25|18| 7|12| 3|
ןמאמg


