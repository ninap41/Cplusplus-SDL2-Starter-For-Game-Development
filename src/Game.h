
# pragma once
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

class Game 
{
    public:
    Game();
    virtual ~Game();

    //operators

    //functions
    void mainMenu();

    //accessors
    inline bool isPlayin() const { return this->playing; }

    //modifiers

private:
    int choice;
    bool playing;
};