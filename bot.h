#include <iostream>
#include "helpers.h"
#include "funcs.h"

const int MAX_GENES = 10;

int switch_to(int step)
{
    if (step * 2 < MAX_GENES) return step * 2;
    else return step * 2 - MAX_GENES;
}

class Bot
{
    private:
        int genes[MAX_GENES];
        // unsigned int energy;
        unsigned int health;
        unsigned int food;
    public:
        bool alive;
        int steep;
        int steps;
        Bot(int[]);
        int step(int);
        ~Bot();
};

Bot::Bot(int genes[MAX_GENES])
{
    std::cout << "Creating new life\n";
    for (int i = 0; i < MAX_GENES; i++)
        this->genes[i] = genes[i];
    
    

    std::cout << "\nGenes:\n";
    for (int i = 0; i < MAX_GENES; i++)
    {
        if (i == MAX_GENES/2) std::cout << std::endl;
        print_genes(genes, i);
    }
    std::cout << std::endl;

    std::cout << "\n";

    this->alive = true;
    this->steep = 0;
    this->steps = 0;
    this->food = 3;
    this->health = 1;
    // this->energy = 3;
}

Bot::~Bot()
{
    std::cout << "Bot is dead\n";
    std::cout << "Bot's steps: " << this->steps;
}

int Bot::step(int steep)
{
    if (this->health == 0)
    {
        this->alive = false;
        return -1;
    }
    if (this->food == 0) this->health--;
    if (this->steep == MAX_GENES) this->steep = rand() % MAX_GENES;
    switch (genes[steep])
    {
        case IDLE:
            std::cout << "Idle\n";
            break;
        case MOVE_L:
            std::cout << "Move left\n";
            break;
        case MOVE_R:
            std::cout << "Move right\n";
            break;
        case MOVE_U:
            std::cout << "Move up\n";
            break;
        case MOVE_D:
            std::cout << "Move down\n";
            break;
        case EAT:
            std::cout << "Eat\n";
            this->food += 1;
            break;
        // case CHK_EN:
        //     std::cout << "Energy: " << this->energy << "\n";
        //     //если энергии нет, то перевести в IDLE
        //     if (energy == 0) step(IDLE);
        //     break;
        case CHK_FD:
            std::cout << "Food: " << this->food << "\n";
            break;
        case ATTACK:
            std::cout << "Attack\n";
            break;
        // case SWH_TO:
        //     std::cout << "Switch to (" << switch_to(this->steep) << ") ";
        //     print_genes(this->genes, switch_to(this->steep));
        //     std::cout << "\n";
        //     this->steep = switch_to(this->steep);
        //     break;
    }
    // this->energy--;
    if (this->food != 0) this->food--;
    this->steep++;
    this->steps++;
    //если все хорошо, то вернем 1
    //иначе возвращаем -1

    return 1;
}

