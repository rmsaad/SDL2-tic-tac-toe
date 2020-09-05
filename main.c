/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Rami
 *
 * Created on September 1, 2018, 9:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "TicTacToeVar.h"
#include "render.h"
#include "logic.h"


/*function prototypes*/
bool process_events(SDL_Window *window, game *game);
void render_stuff(SDL_Renderer *renderer, game *game);

/*main: controls logic for a game of TicTacToe*/
int main(int argc, char** argv) {
    game game = {
        .board ={empty, empty, empty,
                 empty, empty, empty,
                 empty, empty, empty},
        .player_turn  = x,
        .game_process = running
    };
    
    SDL_Init(SDL_INIT_VIDEO);                                                   // Initialize SDL
    SDL_Window *window;                                                         // Declare a window     
    SDL_Renderer *renderer;                                                     // Declare a renderer
    
    //Window Application settings
    window = SDL_CreateWindow("TicTacToe",                                      // Window Title
                              SDL_WINDOWPOS_UNDEFINED,                          // Initial x position
                              SDL_WINDOWPOS_UNDEFINED,                          // Initial y position
                              SCREEN_WIDTH,                                     // Width
                              SCREEN_HEIGHT,                                    // Height
                              0                                                 // Flags
                              );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |        // Creates renderer
                                              SDL_RENDERER_PRESENTVSYNC);       // ...
    
    bool running = true;                                                        // Flag for event loop
    while(running){                                                             // Event loop
        running = process_events(window, &game);                                // Check for events
        render_stuff(renderer, &game);                                          // Renders thing to screen
    }
    
    SDL_DestroyWindow(window);                                                  // Release resources from memory...      
    SDL_DestroyRenderer(renderer);                                              // ...
    SDL_Quit();                                                                 // ...
    
    return (EXIT_SUCCESS);
}

/*process_events: checks for events*/
bool process_events(SDL_Window *window, game *game){
    SDL_Event event;
    
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return false;
        }
        else if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                click_on_cell(game,
                              event.button.x/ CELL_WIDTH,
                              event.button.y/ CELL_HEIGHT);
            }
        }
    }
    return true;
}

/*render_stuff: renders things to the screen*/
void render_stuff(SDL_Renderer *renderer,game *game){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);          // Color to render
    SDL_RenderClear(renderer);                                                  // Set Background color to white
    render_game(renderer, game);                                                // Render game 
    SDL_RenderPresent(renderer);                                                // Show to screen what has been drawn
}
