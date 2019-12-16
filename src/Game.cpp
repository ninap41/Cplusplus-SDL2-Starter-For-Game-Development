#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

#include "Game.h"
 
Game::Game()
{
    choice = 0;
    playing = true;
}

Game::~Game()
{

}

void Game::mainMenu() 
{
    std::cout << "Main Menu" << std::endl;
    std::cout << "0:quit" << std::endl;
};
