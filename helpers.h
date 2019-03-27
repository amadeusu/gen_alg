#ifndef HELPERS_H
#define HELPERS_H

const int GENES = 8;

enum gen {
    IDLE,
    MOVE_L,
    MOVE_R,
    MOVE_U,
    MOVE_D,
    EAT,
    //CHK_EN,
    CHK_FD,
    ATTACK,
    // SWH_TO,
};

#endif