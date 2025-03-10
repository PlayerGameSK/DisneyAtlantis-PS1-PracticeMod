#ifndef SYMBOLS_H
#define SYMBOLS_H
#include <custom_types.h>

//You can define in game variables & functions like so:
//You MUST put a comment with the address at the end:

//In Game Variables:
in_game int* ptr_player; //0x80096868
in_game int barrel_position; //0x800B3EDC

in_game long button_press; //0x800969D8
in_game long unlocked_levels; //0x80098F3C
in_game long load_next; //0x800AAE8C

in_game short game_state; //0x80095C16
in_game short game_complete; //0x80098F3E
in_game short selected_level; //0x800AAEE8

in_game short player_health; //0x80096762
in_game short player_lives; //0x80096760
in_game short truck_gas; //0x80096766

in_game short leviathan_health; //0x80096772

in_game short current_level; //0x80098F58
in_game short next_level; //0x800956AE
in_game short outer_state; //0x80098F74

in_game long OuterAtlantis_name1; //0x8009DAC8
in_game long OuterAtlantis_name2; //0x8009DACC

in_game long Collectibles1; //0x80098F5C
in_game long Collectibles2; //0x80098F60
in_game long Collectibles3; //0x80098F64
in_game long Collectibles4; //0x80098F68
in_game long GreenCrystals_Collected; //0x80098F40
in_game short GreenCrystals_Amount; //0x8009676C

//In Game Functions:
in_game void InGameFunction(int arg1, char* arg2); //0x80005678

#endif //SYMBOLS_H
