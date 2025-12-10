#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int has_won (int board [6][7]);
int move (int board [6][7], int move, int turn);
void print(int board [6][7]);

int main () {
    
    char game_ending [50] = "y";
    int moves_made = 0;
    
    while (!strcmp("y", game_ending)) {
        //resets the moves made while in the inital loop
        moves_made = 0;
        int board [6][7] = {0};
        int turn = 1;
        int winner = 0;
        char user_move_input_char [50];
        
        print(board);
        
        while(winner == 0 && moves_made < 42){
            if (turn == 1) {
                printf("Player 1 (x), please enter a move (1-7):\n>>>");
            }
            else {
                printf("Player 2 (o), please enter a move (1-7):\n>>>"); 
            }
            scanf(" %s", user_move_input_char);
            
            if(!strcmp("1", user_move_input_char) ||!strcmp("2", user_move_input_char)||!strcmp("3", user_move_input_char)||!strcmp("4", user_move_input_char)||!strcmp("5", user_move_input_char)||!strcmp("6", user_move_input_char)||!strcmp("7", user_move_input_char)) {
                int user_move_input = atoi(user_move_input_char);
                
                move(board, user_move_input, turn);
                
                //alternates the turns from X and O
                turn *= -1;
                
                // if someone wins the game, winner will be set to -1 or 1
                winner = has_won(board);
                
                //counts the moves made as the game is going
                moves_made++;
                
                print(board);
                
                if(winner == 1){
                    printf("Player 1 has won!\n");
                }
                else if(winner == -1){
                    printf("Player 2 has won!\n");
                }
                
            }
            else {
                printf("Invalid move\n");
            }
            
        }

        // the game will only reach 42 moves if the game is tied
        if(moves_made == 42){
            printf("The game was a draw!\n");
        }
        
        printf("Would you like to play again? y/n");
        scanf(" %s", game_ending);
        
        while(strcmp("y", game_ending) && strcmp("n", game_ending)){
            printf("Invalid input\n");
            printf("Would you like to play again? y/n");
            scanf(" %s", game_ending);
        }
        
    }
    
    return 0;
}


int has_won (int board [6][7]) {
    
    //checks rows
    for (int i = 0; i < 6; i ++) {
        for (int j = 0; j < 4; j++) {
            if (board [i][j] && board [i][j +1] == board [i][j] && board [i][j+2] == board [i][j] && board [i][j +3] == board [i][j]) {
            //this player will have won
            return board [i][j];
            }
        }
    }
    
    //checks columns
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 7; j ++) {
            if (board[i][j] && board[i + 1][j] == board[i][j] && board[i +2][j] == board[i][j] && board[i +3][j] == board[i][j]){
                //whichever player has 4 in a row
                return board[i][j];
            }
        }
    }
    
    //check diagonals
    for (int i = 3; i < 6; i ++){
        for (int j = 0; j < 4; j ++) {
            if (board[i][j] && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return board[i][j];
            }
        }
    }
    
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 4; j ++) {
            if (board[i][j] && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return board[i][j];
            }
        }
    }
    
    //no one has won
    return 0;
}

int move (int board[6][7], int move, int turn){
    if(move < 1 || move > 7){
        printf("Invalid input.\n");
        return 0;
    }
    
    int row = 5;  // start from the bottom row
    
    while (row >= 0 && board[row][move - 1] != 0) {
        row--;  // move up if the current row is not empty
    }

    // check if the move is within the valid range
    if (row >= 0) {
        board[row][move - 1] = turn;
    } else {
        // for when the column is full
        printf("Invalid input.\n");
    }
    
    return 0;
}

void print(int board [6][7]) {
    for (int i = 0; i < 6; i ++) {
        for (int j = 0; j < 7; j ++){
            //the input is equal to X
            if (board[i][j] == 1) {
                printf("x");
            }
            //the input is equal to O
            else if (board[i][j] == -1) {
                printf("o");
            }
            // blank space
            else {
                printf("_");
            }
        }
        printf("\n");
    }
}
