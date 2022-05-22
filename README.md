# CS4386-AI-Game-Programming

<b><h3> Minimax algorithm is used to solve assignment1.</h3> <b>

 <b> <h4> Assignment 1 brief description : </h4> </b>

For detail description, please check out the Assignment1Details text file uploaded.
 
Game: 3-14 

Gameplay: 3-14 is a 2-player turn-based game. Initially there is a pile of 9 numbers: 0,1,2,3,4,5,6,7,8. Each player takes turn to choose a number from the pile. After a number is chosen, it will be removed from the pile and inserted into the player’s hand. The game ends when a player wins or when it is a draw game that the last number is chosen by the player who does not win.

Winning Condition: A player wins the game if the player’s hand contains 3 numbers whose sum is 14.

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


 <h3> A* algorithm is used to solve assignment2. </h3>

<h4> Assignment 2 detail: </h4>
 
For detail description, please check out the Assignment2Details text file uploaded. 
 
3x3 Sliding Puzzle
 
Gameboard: the gameboard of a 3x3 sliding puzzle contains 3x3 cells. Here we will label the cell locations as A-I from top to bottom, left to right, i.e.,

A	B	C
D	E	F
G	H	I
There are 8 tiles which are placed on different cells. This also means that one of the 9 cells does not contain any tile, and thus empty. Here we will label the tiles as 1-8, and we also label the empty cell as 0. 

Winning Condition: The puzzle is solved if it reaches the following pattern:

0	1	2
3	4	5
6	7	8

Example:

![image](https://user-images.githubusercontent.com/42562789/169710156-22d9cee5-4aa6-4f70-a917-d620f66447d9.png)

