void print_genes(int* genes, int i)
{
    switch(genes[i])
    {
        case IDLE:
            std::cout << "IDLE\t";
            break;
        case MOVE_L:
            std::cout << "MOVE_L\t";
            break;
        case MOVE_R:
            std::cout << "MOVE_R\t";
            break;
        case MOVE_U:
            std::cout << "MOVE_U\t";
            break;
        case MOVE_D:
            std::cout << "MOVE_D\t";
            break;
        case EAT:
            std::cout << "EAT\t";
            break;
        // case CHK_EN:
        //     std::cout << "CHK_EN\t";
        //     break;
        case CHK_FD:
            std::cout << "CHK_FD\t";
            break;
        case ATTACK:
            std::cout << "ATTACK\t";
            break;
        // case SWH_TO:
        //     std::cout << "SWH_TO\t";
        //     break;
    }
}
