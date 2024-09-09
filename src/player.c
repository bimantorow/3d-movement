#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "utils.h"

Player *Player_Create(void) {
    Player *player = malloc(sizeof(Player));
    bzero(player, sizeof(Player)); 
    return player;
}

void Player_Free(Player *player) {
    free(player);
}