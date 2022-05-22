# CS4386-AI-Game-Programming

Minimax algorithm is used to solve assignment1.

<b> Assignment 1 detail: </b>

Game: 3-14

Gameplay: 3-14 is a 2-player turn-based game. Initially there is a pile of 9 numbers: 0,1,2,3,4,5,6,7,8. Each player takes turn to choose a number from the pile. After a number is chosen, it will be removed from the pile and inserted into the player’s hand. The game ends when a player wins or when it is a draw game that the last number is chosen by the player who does not win.

 

Winning Condition: A player wins the game if the player’s hand contains 3 numbers whose sum is 14.

For example, if a player’s hand contains 1,4,8:

if the player chooses 2 from the pile (if available), then the player’s hand becomes 1,2,4,8, and the player would win the game because 2+4+8=14
if the player chooses 5 from the pile (if available), then the player’s hand becomes 1,4,5,8, and the player still would win the game because 1+5+8=14
however, if the player chooses 6 from the pile (if available), then the player’s hand becomes 1,4,6,8, but the player would not win because all possible sums of 3 numbers are not equal to 14 (1+4+6=11, 1+4+8=13, 1+6+8=15, 4+6+8=18). The fact that 6+8=14 is irrelevant because the sum must be obtained from exactly 3 numbers.
 

To Do: Write a program that

reads some input data indicating the status of a game
contains an AI algorithm to make a move for the current player by choosing a number from the pile and try to achieve the winning condition
output the updated status of the game

Input: The input should be read from the standard input stream that contains a sequence of numbers separated by space. The first number indicates how many moves have been made by the 2 players in total. The subsequent numbers represent the moves, i.e., the numbers that have been chosen by the 2 players. The following shows an example input:

4 5 2 6 3

In the above example, 4 moves have been made. Player 1 first chooses 5 from the pile; player 2 chooses 2; player 1 chooses 6; player 2 chooses 3. This means that player 1’s hand becomes 5, 6 and player 2’s hand becomes 2,3. The remaining numbers in the pile are thus 0,1,4,7,8. It is player 1’s turn. So given this input text file, your program should choose a number from 0,1,4,7,8 for player 1.

For a new game, there was no previous move. So the input just contains a single number 0.

Output: The output should have the exact format as the input, i.e., it should contain a sequence of numbers where the first number indicates how many moves have been made by the 2 players after you make the move. The subsequent numbers represent the moves that have been chosen by the players, with the last number indicating your move. For example, if you are given the above input and your program chooses 7 from the pile as your move, then the output should be shown as follows:

5 5 2 6 3 7

The output should be produced as the standard output stream.

Time Limit: Your program should generate the output within 2 minutes on any machine that runs your program.

Example:

Starting a new game by inputing a single number 0:
![image](https://user-images.githubusercontent.com/42562789/169709668-a9b8b931-73a0-4c8e-b621-05a4abdad97b.png)
Player 1 chooses 6 from the pile

![image](https://user-images.githubusercontent.com/42562789/169709733-3d398955-2865-4b0d-ac32-af403b43126d.png)
Player 2 chooses 5 from the pile 

![image](https://user-images.githubusercontent.com/42562789/169709801-bac6a49e-915b-49c4-b5d1-016d12396a03.png)
Player 1 chooses 7 from the pile

![image](https://user-images.githubusercontent.com/42562789/169709837-46c469a8-ad4e-40ab-a031-285ebc6aa4f9.png)
Player 2 chooses 1 from the pile

![image](https://user-images.githubusercontent.com/42562789/169709891-3aaa5577-0425-4763-aa13-013ab6f242e2.png)
Player 1 chooses 8 from the pile

You can see that by using the program, every players choose the optimal move.


A* algorithm is used to solve assignment2.

Assignment 2 detail:
3x3 Sliding Puzzle

 

Game demo:  click here to try out the 3x3 sliding puzzle and see how it works download

 

Gameboard: the gameboard of a 3x3 sliding puzzle contains 3x3 cells. Here we will label the cell locations as A-I from top to bottom, left to right, i.e.,

A	B	C
D	E	F
G	H	I
There are 8 tiles which are placed on different cells. This also means that one of the 9 cells does not contain any tile, and thus empty. Here we will label the tiles as 1-8, and we also label the empty cell as 0. 

 

Gameplay: When the sliding puzzle game starts, the numbered tiles appear on the cells in a random order. The following is an example starting puzzle:

3	1	5
0	2	7
6	8	4
You can make a move by sliding a tile to the empty cell, if the cell containing that tile is next to the empty cell (above/below/left/right). In the above example, you can thus slide cell A/E/G to cell D. For example, if you make a move of by sliding the tile in cell A given the above puzzle, then the puzzle will be updated as follows (the tile in cell A is slided to cell D and cell A becomes empty):

0	1	5
3	2	7
6	8	4
You should keep making moves until the puzzle is solved.

 

Winning Condition: The puzzle is solved if it reaches the following pattern:

0	1	2
3	4	5
6	7	8
 

To Do: Write a program that

reads some input data indicating the initial puzzle status
contains an AI algorithm that determines the move sequence that tries to solve the puzzle with as few moves as possible
output the resulting move sequence within the time limit
 

Input: The input should be read from the standard input stream that contains a sequence of 9 digits without space in a random order where each digit 0,1,2,3,4,5,6,7,8 appears only once. The following shows an example input:

315027684

Caution: If you just randomly generate a digit sequence as the input, sometimes there is no solution, i.e., that particular puzzle is not solvable. For example, the puzzle with input 315027648 is NOT solvable. You are advised to use the above given demo  downloadto generate the input for testing, in which case the puzzle is guaranteed to be solvable. 

 

Output: The output should contain the move sequence to solve the given puzzle in the form of characters without space where each character is A-I indicating the cell locations from which the tiles should be slided to the empty cell. For example, the following output would define a move sequence that solves the puzzle given the above input:

ABEFIHEFCBA

The output should be produced as the standard output stream.

 

Time Limit: Your program should generate the output within 5 minutes on any machine that runs your program.

Example:

![image](https://user-images.githubusercontent.com/42562789/169710156-22d9cee5-4aa6-4f70-a917-d620f66447d9.png)

