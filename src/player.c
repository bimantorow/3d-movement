#include <string.h>
#include "player.h"
#include "utils.h"

Player *Player_Create(void) {
    Player *player = malloc(sizeof(player));
    bzero(player, sizeof(player)); 
}

Player *Player_Free(Player *player) {
    free(player);
}