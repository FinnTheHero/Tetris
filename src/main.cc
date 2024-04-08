// Standard libraries
#include <iostream>

// Game libraries
#include "game.h"


int main() {
    Game game;
    
    // Initialization
    

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