
# Disney's Atlantis: The Lost Empire (PS1) Practice Mod
This mod for the PS1 version of Disney's Atlantis: The Lost Empire (NTSC-U) adds various features to aid with speedrun practice. 
Made primarily for the purpose of convenient and accurate (in terms of lag and loads) speedrun practice on PS2, as that is the main platform used for speedruns of the game, but should work on any other platform capable of running PS1 games including emulators.

## Functionality:
### v1.0
1. Save your Character's + Ulysses barrel's Current Position (**L2 + Triangle**) *[does not work for the level "Truck Escape" due to its nature]*
2. Load your Character's + Ulysses barrel's Current Position (**R2 + Triangle**) *[the Ulysses barrel's position will only reload if it hasn't been fully pushed in front of the pipe, if so, you'll first have to restart the level using L3 + R3 and then reload your position]*
3. Go from the Title Screen to the Level Select (**L1 + L2 + R1 + R2**) *[acts as finishing a level, but you can just skip the Save Screen as normal, useful to skip having to Start a New Game if there's no Memory Card present or Save Game to load]*
4. Unlock All Levels (**L3 + R3 on the Level Select screen**)
5. Reset the state of All Collectibles (**Select button on the Level Select screen**)
6. Start New Game from the Level Select (**Hold Square while pressing X on Whitmore's Mansion**)
7. Infinite Health / Lives toggle (During Gameplay: **R3 + L2 to Enable / R3 + R2 to Disable**)
8. Restart the Current Level (During Gameplay: **L3 + R3** | NEW in v1.1: **Use while holding down L2 + R2 to also Reset All Collectibles**)
9. Return to Level Select (During Gameplay: **Triangle + L3 + R2**) *[counts as finishing the level, so it brings you to the Save Screen first]*
10. Stage Select for Outer Atlantis (Press **Square / Circle on it in the Level Select** to pick between its pre-Inner or post-Inner Atlantis state)
11. Insta-Kill Leviathan (**Press Circle** at any time during the boss fight)
12. Infinite Gas in Truck Escape toggle (While in Truck Escape: **Select to Enable / Circle to Disable,** also works while Paused)

## Installation
### Requirements
- an **unmodified ROM of the NTSC-U (American) version of Disney's Atlantis: The Lost Empire for PS1** (none of the PAL releases will work and there are no plans to support them as they are vastly inferior for speedrunning compared to NTSC-U)
- **the mod itself in the form of an .xdelta patch file** which can be found [HERE](https://github.com/PlayerGameSK/DisneyAtlantis-PS1-PracticeMod/releases)
- a RomPatcher capable of patching PS1 games, for example this [Online one by Marc Robledo](https://www.marcrobledo.com/RomPatcher.js) or an offline program like the [Delta Patcher](https://www.romhacking.net/utilities/704)

### Patching the ROM
1. Select your unmodified ROM of the game as the ROM file (if your ROM has 2 tracks, just select Track 1).
2. Select the .xdelta file of the mod as the Patch file.
3. Click Apply patch then download / save the resulting ROM file and you're done!

### Running the patched ROM
For an emulator like DuckStation, all you need to do is open the resulting .bin ROM file you got from the previous step and you should be good to go. 

However if you wish to play it on console, you'll need either a PS2 with [MechaPwn](https://github.com/MechaResearch/MechaPwn) or a modchipped PS1 / PS2, and **you MUST burn the game onto a CD-R disc NOT a DVD of any kind!**

As for burning the disc, I'd recommend making a copy of the original .cue file as well as the Track 2 .bin file (if there is one), then renaming the modded .bin file to the exact same filename as the original and putting all the files together into one folder. Otherwise, you can either edit the .cue file using something like Notepad++ to adjust the filename(s), or generate an entirely new one, using [this website](https://www.duckstation.org/cue-maker). You can also use Composer's Modding Utility to generate both a .bin and a .cue file, though this approach is only really worth it if you know a thing or two about coding and/or are planning to mess with the actual mod's code.


## Compiling & Building
If you wish to compile the mod yourself, here's what you'll have to do:
1. Compiling this mod requires the [C-Game-Modding-Utility by C0mposer](https://github.com/C0mposer/C-Game-Modding-Utility).
2. Once you have downloaded and extracted it, go into its "projects" folder and create a new folder with a name of your choosing, then download / clone this repository into it.
3. Open the Modding Utility then double-click the project's name (same as the folder you created earlier) to open it.
4. Click "Choose PS1 .bin file" then select the .bin file of your original unmodified NTSC-U ROM of Disney's Atlantis (if it has multiple tracks, select Track 1).
5. The Utility will then ask you to select a folder where you wish to extract the game files, this can be pretty much wherever works best for you.
6. **Go into the "Compile" tab then change the "Optimization Level" to O1** (this is necessary, otherwise the mod won't compile) then click "Compile Mod".
7. From here, you're free to open the project in your desired Text Editor, inject the mod into a selection of emulators (as long as there's one running the vanilla game currently), as well as build a patched .bin/.cue ROM of the modded game (as ModdedGame.bin/ModdedGame.cue in the project's folder).
8. If you've made any changes to the code and wish to generate an XDelta patch, I'd recommend using [Delta Patcher](https://www.romhacking.net/utilities/704) - just click the double arrow icon in the bottom-right, then select the unmodified .bin ROM file of the game as the "Original file" (once again, select Track 1 if you have multiple), then select "ModdedGame.bin" from your project's folder after generating it using the Modding Utility as the "Modified file", select where to save the Xdelta patch, optionally add a Description then click "Create patch" and you're all set! 

## Tools Used In Creation:
- [C-Game-Modding-Utility by C0mposer](https://github.com/C0mposer/C-Game-Modding-Utility) for the automation of compiling C code to MIPS object code targeted for the PS1, and hot-reloading the mod into emulators like Bizhawk or DuckStation for quick testing, as well as building a console-ready BIN/CUE with the mod files injected correctly.
- [Bizhawk](https://github.com/TASEmulators/BizHawk) for searching/poking and experimenting with PS1 RAM values easily.
- [DuckStation](https://duckstation.org) for additional testing.
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) in combination with the [PSX Executable Loader Plugin](https://github.com/lab313ru/ghidra_psx_ldr) for analyzing and "reverse engineering" functions in the game.
- [Visual Studio Code](https://code.visualstudio.com) for writing the actual code of the mod.

## Contact
If you need any help building this project, or are looking into making your own PS1 game mod in a similar fashion, feel free to reach out to me on Discord: **PlayerGameSK**

Though if it's the latter, then I'd recommend checking out Composer's and Kara's [Spyro 1 Practice ROM](https://github.com/C0mposer/Spyro-1-Practice-Rom) and getting in contact with them instead, as they are the ones who helped me get into this in the first place, and thus are far more knowledgeable on the subject than I am.
