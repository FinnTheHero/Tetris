// Standard libraries
#include <iostream>

// Game libraries
#include "game.h"


int main() {
    
    // Initialization    
    Game game;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        game.update();
        
        // Draw
        game.draw();
    }

    // De-Initialization
    game.deInit();

    return 0;
}