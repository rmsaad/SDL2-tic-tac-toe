/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SDL2/SDL.h>
#include "TicTacToeVar.h"
#include "render.h"

void render_grid(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);                // Color for grid
    SDL_RenderDrawLine(renderer,   CELL_WIDTH, 0,   CELL_WIDTH, SCREEN_HEIGHT); // Grid for game...
    SDL_RenderDrawLine(renderer, 2*CELL_WIDTH, 0, 2*CELL_WIDTH, SCREEN_HEIGHT); // ...    
    SDL_RenderDrawLine(renderer, 0,   CELL_HEIGHT, SCREEN_WIDTH,   CELL_HEIGHT);// ...
    SDL_RenderDrawLine(renderer, 0, 2*CELL_HEIGHT, SCREEN_WIDTH, 2*CELL_HEIGHT);// ...
}

void render_x(SDL_Renderer *renderer, int col, int row){
    const float half  = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
    const float x_pos = CELL_WIDTH  * 0.5 + col * CELL_WIDTH;
    const float y_pos = CELL_HEIGHT * 0.5 + row * CELL_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_RenderDrawLine(renderer, 
                       x_pos - half,
                       y_pos - half,
                       x_pos + half,
                       y_pos + half
                       );
    SDL_RenderDrawLine(renderer, 
                       x_pos + half,
                       y_pos - half,
                       x_pos - half,
                       y_pos + half
                       );
}

void render_o(SDL_Renderer *renderer, int col, int row){
    const float half  = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
    const float x_pos = CELL_WIDTH  * 0.5 + col * CELL_WIDTH;
    const float y_pos = CELL_HEIGHT * 0.5 + row * CELL_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_RenderDrawLine(renderer, 
                       x_pos - half,
                       y_pos - half,
                       x_pos + half,
                       y_pos + half
                       );
    SDL_RenderDrawLine(renderer, 
                       x_pos + half,
                       y_pos - half,
                       x_pos - half,
                       y_pos + half
                       );
}

void render_board(SDL_Renderer *renderer,const enum board_state board[BOARD_HEIGHT][BOARD_WIDTH]){
     for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            switch(board[i][j]){
                case (x):   render_x(renderer, i, j); break;
                case (o):   render_o(renderer, i, j); break;
                default :   {}
            }
        }
     }

}

void render_running_state(SDL_Renderer *renderer, const game *game){
    render_grid(renderer);
    render_board(renderer, game->board);
}

void render_game_over_state(SDL_Renderer *renderer, const game *game){
    render_grid(renderer);
    render_board(renderer, game->board);
}

void render_tie_state(SDL_Renderer *renderer, const game *game){
    render_grid(renderer);
    render_board(renderer, game->board);    
}

void render_game(SDL_Renderer *renderer, const game *game){
    switch(game->game_process){
        case(running):  render_running_state(renderer, game);   break;
        case(xwin)   :  render_game_over_state(renderer, game); break;
        case(owin)   :  render_game_over_state(renderer, game); break;
        case(tie)    :  render_tie_state(renderer, game);       break;
        default      :  {}
    }
}