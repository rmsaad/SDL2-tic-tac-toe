/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdbool.h>
#include "TicTacToeVar.h"
#include "logic.h"

void switch_player(game *game){
    if(game->player_turn == x)
        game->player_turn = o;
    
    else if(game->player_turn == o)
        game->player_turn = x;
}

bool check_player_win(game *game, enum board_state player_turn){ 
    
    for(int i = 0; i < BOARD_HEIGHT; i++){                                      // Check vertical...
        if(game->board[i][0] == player_turn){                                   // ...
            if (game->board[i][0] == game->board[i][1] &&                       // ...
                game->board[i][1] == game->board[i][2]){                        // ...
                return true;                                                    // ...
            }                                                                   // ...
        }                                                                       // ...
    }                                                                           // ...
    
    for(int i = 0; i < BOARD_WIDTH; i++){                                       // Check horizontal...
        if(game->board[0][i] == player_turn){                                   // ...
            if (game->board[0][i] == game->board[1][i] &&                       // ...
                game->board[1][i] == game->board[2][i]){                        // ...
                return true;                                                    // ...
            }                                                                   // ...        
        }                                                                       // ...
    }                                                                           // ...
    
    if(game->board[0][0] == player_turn)                                        // Check Diagonal...
        if(game->board[0][0] == game->board[1][1] &&                            // ...   
           game->board[1][1] == game->board[2][2])                              // ...
            return true;                                                        // ...
        
    if(game->board[0][2] == player_turn)                                        // ...
        if(game->board[0][2] == game->board[1][1] &&                            // ...
           game->board[1][1] == game->board[2][0])                              // ...
            return true;                                                        // ...
 
    return false;
}

int count_cells(const enum board_state board[BOARD_HEIGHT][BOARD_WIDTH], enum board_state cell){
    int count = 0;
    for(int i = 0; i < BOARD_HEIGHT; i++)
        for(int j = 0; j < BOARD_WIDTH; j++)
            if (board[i][j] == cell)
                count++;
    return count;    
        
}

void game_over_condition(game *game){
    if(check_player_win(game, x))
        game->game_process = xwin;
    else if(check_player_win(game, o))
        game->game_process = owin;
    else if(count_cells(game->board, empty) == 0)
        game->game_process = tie;
}

void player_turn(game *game, int col, int row){
    if(game->board[col][row] == empty){
        game->board[col][row] = game->player_turn;
        switch_player(game);
        game_over_condition(game);
    }
}

void reset_game(game *game){
    game->player_turn = x;
    game->game_process = running;
    for(int i = 0; i < BOARD_HEIGHT; i++)
        for(int j = 0; j < BOARD_WIDTH; j++)
            game->board[i][j] = empty;
}

void click_on_cell(game *game, int col, int row){
    if (game->game_process == running){
        player_turn(game, col, row);
    }else{
        reset_game(game);
    }
}