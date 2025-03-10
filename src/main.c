#include <custom_types.h>
#include <symbols.h>

void MemCpy(void *dest, void *src, int n) 
{ 
// Typecast src and dest addresses to (char *) 
char *csrc = (char *)src; 
char *cdest = (char *)dest; 

// Copy contents of src[] to dest[] 
for (int i=0; i<n; i++) 
    cdest[i] = csrc[i]; 
} 

// Define Level IDs
#define MAINMENU 0x1
#define WHITMORE 0x2
#define ULYSSES 0x3
#define LEVIATHAN 0x4
#define COVE 0x5
#define ICE 0x6
#define FIRE 0x7
#define TRUCK 0x8
#define OUTER 0x9
#define INNER 0xA
#define SECRET 0xB
#define TREACHERY 0xC
#define AKTIRAK 0xD
#define SAVEKIDA 0xE
#define LEVELSELECT 0xF
#define BONUS1 0x0011
#define BONUS2 0x0012
#define BONUS3 0x0013
#define BONUS4 0x0014
#define BONUS5 0x0015

// Define Game States
#define GAMEPLAY 0x2
#define MENUS 0x3
#define PAUSED 0x4
#define INVENTORY 0x5
#define RELOAD 0x6

// Define custom variables
bool infiniteHealth = false;
bool infiniteGas = false;
short level_now;

// Define save state space
int savestate_free_space[12] = {0};

void CustomFunction(void)
{

    // Save Player Position (L2 + Triangle)
    if (game_state == GAMEPLAY && button_press == 0x1100 && current_level != TRUCK)
    {
        level_now = current_level;
        MemCpy(&savestate_free_space[0], ptr_player, 0x4);
        MemCpy(&savestate_free_space[1], ptr_player + 1, 0x4);
        MemCpy(&savestate_free_space[2], ptr_player + 2, 0x4);
        MemCpy(&savestate_free_space[3], ptr_player + 3, 0x4);
        MemCpy(&savestate_free_space[4], ptr_player + 11, 0x4);
        MemCpy(&savestate_free_space[5], ptr_player + 53, 0x4);
        MemCpy(&savestate_free_space[6], ptr_player + 54, 0x4);
        MemCpy(&savestate_free_space[7], ptr_player + 55, 0x4);
        MemCpy(&savestate_free_space[8], ptr_player + 56, 0x4);
        MemCpy(&savestate_free_space[9], ptr_player + 57, 0x4);
        MemCpy(&savestate_free_space[10], ptr_player + 58, 0x4);
        if(current_level == ULYSSES)
        {
        MemCpy(&savestate_free_space[11], &barrel_position, 0x4);            
        }
    }

    // Load Player Position (R2 + Triangle)
    if (game_state == GAMEPLAY && button_press == 0x1200 && current_level == level_now && current_level != TRUCK)
    {
        MemCpy(ptr_player, &savestate_free_space[0], 0x4);
        MemCpy(ptr_player + 1, &savestate_free_space[1], 0x4);
        MemCpy(ptr_player + 2, &savestate_free_space[2], 0x4);
        MemCpy(ptr_player + 3, &savestate_free_space[3], 0x4);
        MemCpy(ptr_player + 11, &savestate_free_space[4], 0x4);
        MemCpy(ptr_player + 53, &savestate_free_space[5], 0x4);
        MemCpy(ptr_player + 54, &savestate_free_space[6], 0x4);
        MemCpy(ptr_player + 55, &savestate_free_space[7], 0x4);
        MemCpy(ptr_player + 56, &savestate_free_space[8], 0x4);
        MemCpy(ptr_player + 57, &savestate_free_space[9], 0x4);
        MemCpy(ptr_player + 58, &savestate_free_space[10], 0x4);
        if(current_level == ULYSSES)
        {
        MemCpy(&barrel_position, &savestate_free_space[11], 0x4);            
        }
    }

    // Press X while holding Square when selecting Whitmore's Mansion to Start New Game
    if (selected_level == 0x0000 && button_press == 0xC000)
    {
        load_next = 0x0015;
    }

    // Go to Level Select if all shoulder buttons are pressed in the Main Menu(s)
    if (game_state == MENUS && button_press == 0x0F00)
    {
    next_level = LEVELSELECT;
    game_state = RELOAD;
    }

    // Unlock All Levels (L3 + R3 in the Menu) / Reset the state of All Collectibles (Select in the Menu)
    if (game_state == MENUS)
    {
        if(button_press == 0x0006)
        {
            unlocked_levels = 0xFFFF;
            game_complete = 0x1;
        }
        if(button_press == 0x0001)
        {
            Collectibles1 = 0x00000000;
            Collectibles2 = 0x00000000;
            Collectibles3 = 0x00000000;
            Collectibles4 = 0x00000000;
            GreenCrystals_Collected = 0x00000000;
            GreenCrystals_Amount = 0x0;
        }
    }

    // Restart Level (L3 + R3 during Gameplay)
    if (game_state == GAMEPLAY)
    {
        if(button_press == 0x0006)
        {
            game_state = RELOAD;
        }
    }

    // Return to Level Select (Triangle + L3 + R2)
    if (game_state == GAMEPLAY && button_press == 0x1202)
    {
        next_level = LEVELSELECT;
        game_state = RELOAD;
    }

    // Outer Atlantis STAGE SELECT (Square OR Circle when its highlighted in the menu)
    if (game_state == MENUS && selected_level == 0x7 && button_press == 0x8000)
    {
        outer_state = 0x0000;
        OuterAtlantis_name1 = 0x6E4F2072;
        OuterAtlantis_name2 = 0x746E0065;
    }
    if (game_state == MENUS && selected_level == 0x7 && button_press == 0x2000)
    {
        outer_state = 0x0001;
        OuterAtlantis_name1 = 0x77542072;
        OuterAtlantis_name2 = 0x006F006F;
    }

    // Insta-Kill Leviathan (Circle)
    if (current_level == LEVIATHAN && button_press == 0x2000)
        {
            leviathan_health = 0;
        }

    // Infinite Health toggle (R3 + L2 to Enable / R3 + R2 to Disable)
    if (game_state != MENUS && button_press == 0x0104)
    {
        infiniteHealth = true;
    }

    if (infiniteHealth == true)
    {
        player_health = 0x64;
        player_lives = 0x7;
    }

    if (game_state != MENUS && button_press == 0x0204)
    {
        infiniteHealth = false;
        player_health = 0x32;
        player_lives = 0x5;
    }
    
    // Infinite Gas in Truck Escape (Select to Enable / Circle to Disable, also works while Paused)
    if (current_level == TRUCK && button_press == 0x0001)
    {
        infiniteGas = true;
    }

    if (infiniteGas == true)
    {
        truck_gas = 0x64;
    }

    if (current_level == TRUCK && infiniteGas == true && button_press == 0x2000)
    {
        infiniteGas = false;
        truck_gas = 0x63;
    }
    return;
}