#include <iostream>
#include <cstdlib>

#include "bot.h"
//#include "helpers.h"
//#include "funcs.h"

// int now_step = 0;
// int old_step = 0;
// int best_bot;

// void write_record(int step)
// {
//     int middle;
//     middle = now_step;
//     now_step = step;
//     old_step = middle;
// }

int best_steps = 0;

int* try_live(int *genes, bool first_pop = true)
{
    
    if (!first_pop)
    {
        int random_gene = rand() % MAX_GENES;
        genes[random_gene] = rand() % GENES;
    }

    Bot *bot = new Bot(genes);
    
    for ( ; ; )
    {   
        if (bot->alive == false)
        {
            // write_record(bot->steps);
            // std::cout << "Bot's steps: " << bot->steps << std::endl; 
            if (bot->steps > best_steps) best_steps = bot->steps;
            bot->~Bot();
            break;
        }
        bot->step(bot->steep);
    }
    
    return genes;
}

int* create_genes()
{
    int *array = new int[MAX_GENES];
    for (int i = 0; i < MAX_GENES; i++)
    {
        array[i] = rand() % GENES;
    }

    return array;
}

void try_lives(int iter_count)
{
    int *genes = create_genes();
    genes = try_live(genes);
    
    for (int i = 0; i < iter_count; i++)
    {
        // if (now_step != old_step || old_step < now_step) best_bot = i;
        std::cout << "\nNew life #" << i << "\n";

        genes = try_live(genes, false);
    }

    // std::cout << "Best bot is #" << best_bot << std::endl;
    std::cout << "\nBest steps: " << best_steps << "\n";
}

int main (void)
{
    srand((unsigned int)time(NULL));
    
    try_lives(500000);

    return 0;
}