#include <bits/stdc++.h> 
using namespace std;


int player = 0;

// Initial values of 
// Aplha and Beta 
const int MAX = 1000; 
const int MIN = -1000; 

bool gameOver(int board[]){
	
	for(int i=0; i<9; i++){
		if(board[i] == 0){
			return false;
		}
	}
	return true;
}

int evaluate(vector<int> player1Move, vector<int> player2Move) {
	
	int sum=14;
 	 
 	if(player1Move.size() >=3){
		for (int i = 0; i < player1Move.size() - 2; i++)  
	    { 
	        // Find pair in subarray A[i+1..n-1] 
	        // with sum equal to sum - A[i] 
	        unordered_set<int> s; 
	        int curr_sum = sum - player1Move[i]; 
	        for (int j = i + 1; j < player1Move.size(); j++)  
	        { 
	            if (s.find(curr_sum - player1Move[j]) != s.end())  
	            { 
	                //printf("Triplet is %d, %d, %d", player1Move[i],player1Move[j], curr_sum - player1Move[j]); 
	                if(player == 1){
	                	return 10;
					}
					else{
	                	return -10;
					} 
	            } 
	            s.insert(player1Move[j]); 
	        } 
	    } 
	}
	
	if(player2Move.size() >=3){
		for (int i = 0; i < player2Move.size() - 2; i++)  
	    { 
	        // Find pair in subarray A[i+1..n-1] 
	        // with sum equal to sum - A[i] 
	        unordered_set<int> s; 
	        int curr_sum = sum - player2Move[i]; 
	        for (int j = i + 1; j < player2Move.size(); j++)  
	        { 
	            if (s.find(curr_sum - player2Move[j]) != s.end())  
	            { 
	                //printf("Triplet is %d, %d, %d", player2Move[i],player2Move[j], curr_sum - player2Move[j]);  
	                if(player == 2){
	                	return 10;
					}
					else{
	                	return -10;
					} 
	            } 
	            s.insert(player2Move[j]); 
	        } 
	    } 
	}
	return 0;
	
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(int board[], vector<int> player1Move,  vector<int> player2Move, int depth, bool isMax, int alpha, int beta)
{
    int score = evaluate(player1Move,  player2Move);
 	//cout << score << endl; 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score-depth;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score+depth;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (gameOver(board)==true){
		//cout << "gg" << endl;
        return 0;
    }
 
    // If this maximizer's move
    if (isMax)
    {
        int best = MIN;
 
        // Traverse all cells
        for (int i = 0; i<9; i++)
        {
 
                // Check if cell is empty
                if (board[i]==0)
                {
                    // Make the move
                    board[i] = 1;
                    if(player == 1){
                    	player1Move.push_back(i);
					}
					else{
						player2Move.push_back(i);
					}
 					
                    // Call minimax recursively and choose
                    // the maximum value
                    //cout << "maximumer " << i << endl;
                    int val = minimax(board, player1Move, player2Move, depth+1, !isMax, alpha, beta);
 					
                    // Undo the move
                    board[i] = 0;
                    if(player == 1){
                    	player1Move.pop_back();
					}
					else{
						player2Move.pop_back();
					}
 					
 					best = max(best,val);
 					alpha = max(alpha, best);
 					
 					if(beta <= alpha)
 						break;
 					
                }
            
        }
        return best;
    }
 
 	// If this minimizer's move
    else
    {
        int best = MAX;
 
        // Traverse all cells
        for (int i = 0; i<9; i++)
        {
                // Check if cell is empty
                if (board[i]==0)
                {
                    // Make the move
                    board[i] = 1;
                    if(player == 1){
                    	player2Move.push_back(i);
					}
					else{
						player1Move.push_back(i);
					}
 
                    // Call minimax recursively and choose
                    // the minimum value
                    //cout << "minimzer " << i << endl;
                    int val =  minimax(board, player1Move, player2Move, depth+1, !isMax, alpha, beta);
 					
                    // Undo the move
                    board[i] = 0;
                    if(player == 1){
                    	player2Move.pop_back();
					}
					else{
						player1Move.pop_back();
					}
					
				    best = min(best, val); 
           			beta = min(beta, best); 
  
          			  // Alpha Beta Pruning 
          		    if (beta <= alpha) 
                        break; 
                }
            
        }
        return best;
    }
 
 
}



// This will return the best possible move for the player
int findBestMove(int board[], vector<int> player1Move, vector<int> player2Move)
{
    int bestVal = -1000;
    int bestMove = -1000; 
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<9; i++)
    {
            // Check if cell is empty
            if (board[i] == 0)
            {
                // Make the move
                board[i] = 1;
 				if(player == 1){
                   	player1Move.push_back(i);
				}
				else{
					player2Move.push_back(i);
				}
 				//cout << i << " yes" << endl;
 		 
                // compute evaluation function for this
                // move.
                //cout<< "round " << i << ":"  << endl;
                int moveVal = minimax(board, player1Move, player2Move,0, false, MIN, MAX);
 				//cout << endl;	
                // Undo the move
                board[i] = 0;
 				if(player == 1){
                   	player1Move.pop_back();
				}
				else{
					player2Move.pop_back();
				}
                // If the value of the current move is
                // more than the best value, then update
                // best/
               //cout << moveVal << endl;
                if (moveVal > bestVal)
                {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }
        
    }
    //printf("The value of the best Move is : %d\n\n",bestVal);
    return bestMove;
}


int main(int argc, char** argv){

	int num_move = stoi(argv[1]);
	int number_checked[9];  
	
	if(num_move %2 ==0){
		player = 1;
	}
	else{
		player = 2;
	}
	
	vector<int> player1Move;
	vector<int> player2Move;
	//cout << argv[2];
	
	for (int i = 0; i < 9; i++){
		number_checked[i] = 0;	
	}
	
	int cntPlayer1=0;
	int cntPlayer2=0;
	for (int i = 0; i < num_move; i++) {
		if(i%2 == 0){
			player1Move.push_back( stoi(argv[i + 2]) );
			number_checked[stoi(argv[i + 2])] = 1; 
		}
		else{
			player2Move.push_back( stoi(argv[i + 2]) );
			number_checked[stoi(argv[i + 2])] = 1; 
		}
	}
	
/*	for(int i=0; i < 9; i++){
		cout << number_checked[i] << " " << i << endl;
	}*/
	
/*	for(int i=0 ; i<cntPlayer1; i++){
		cout << player1Move[i] << " ";
	}
	
	cout << endl;
	
	for(int i=0 ; i<cntPlayer2; i++){
		cout << player2Move[i] << " ";
	} */
	
	//cout << evaluate( player1Move, cntPlayer1, player2Move, cntPlayer2  ) ;
//	if(num_move == 0){
//		cout << 6 << endl;
//	}
//	else{
	
	int bestMove = findBestMove(number_checked, player1Move, player2Move);
	
	for(int i=1; i< argc;i++){
		if(i==1){
			cout << stoi(argv[i])+1 << " ";
		}
		else{
			cout << stoi(argv[i]) << " "; 
		}
	}
 
	cout << bestMove;
	
	
//	}
	
	return 0;

}
