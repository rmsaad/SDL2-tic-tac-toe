/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToeVar.h
 * Author: Rami
 *
 * Created on September 2, 2018, 4:37 PM
 */

#ifndef TICTACTOEVAR_H
#define TICTACTOEVAR_H

#define BOARD_HEIGHT    3
#define BOARD_WIDTH     3
#define BOARD_SPACES    9
#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define CELL_WIDTH  (SCREEN_WIDTH/BOARD_WIDTH)
#define CELL_HEIGHT (SCREEN_HEIGHT/BOARD_HEIGHT)

enum board_state{empty, x, o};
enum game_state{running, xwin, owin, tie};

typedef struct{
    enum board_state board[BOARD_HEIGHT][BOARD_WIDTH];
    enum board_state player_turn;
    enum game_state game_process; 
}game;

#endif /* TICTACTOEVAR_H */

