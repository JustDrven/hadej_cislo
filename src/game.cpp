#include "game.h"
#include "../utils/colors.h"
#include "../utils/console.h"

Game::Game(int& count_of_guesses) {
    this->count_of_guesses = count_of_guesses;
}

void Game::End() {
    Console::print_line(ColorBase::RED + "     Prohrál jsi" + ColorBase::RESET);
}

void Game::Win() {
    Console::print_line(ColorBase::GREEN + "     Vyhrál jsi" + ColorBase::RESET);
    Console::print_line("Číslo jsi uhádl na " + to_string(count_of_guesses) + ". pokus");
}