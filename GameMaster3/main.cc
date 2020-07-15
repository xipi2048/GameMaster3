#include "GameContext.h"

//Thanks to https://learnopengl.com/ for the great tutorial!

int main(int argc, char **argv)
{ 
    GameContext game;
    if (game.init())
        game.run();

    return 0;
}