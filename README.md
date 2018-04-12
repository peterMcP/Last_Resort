# Circus Games

### new Project GitHub: https://github.com/CircusGames/Last_Resort

### v0.3 GitHub https://github.com/CircusGames/Last_Resort

   * Build:  https://github.com/CircusGames/Last_Resort/releases

### v0.2.1 GitHub: https://github.com/CircusGames/Last_Resort
  
   * Build: https://github.com/CircusGames/Last_Resort/releases
   
***   

### old Project GitHub: https://github.com/dusthandler/CITM_Proyecto_1

### v0.2 GitHub: https://github.com/dusthandler/CITM_Proyecto_1

   * Build: https://github.com/dusthandler/CITM_Proyecto_1/releases
   
***

### v0.1 GitHub: https://github.com/peterMcP/SDL3_Handout

   * Build: https://github.com/peterMcP/SDL3_Handout/releases
   
***
   
Instructions:

   * Use keyboard keys:
      * W,a,s,d to move player ship up,left,down and right.
	  * Left Shift to lock/unlock Unity.
	  * Space to shot simple beam.
	  * Return to switch game scenes.

***

### changelog v0.3

   * Added moduleParticles:
      * modified to accept, speed, life, and sourceAnimation.
	  * SourceAnimation is used to link pointer of structure particles to animation.
	  * SourceAnimation is created to coexist with animations dynamic memory destructor.
   * Splitted ModuleScene into two separated modules, gameTitle and teamLogo:
      * gameTitle now have full animations and logic.
   * Added Player Unity Module:
      * Contains the logic and animations of the basic weapon of the game, the unity.
	  * Full linear and diagonals moves respect the player position.
	  * Links correctly the flow of the Unity animation itself.
	  * NOT CONTEMPLED YET: diagonals of the unity animation itself (where it's pointing with diagonal press).
   * Adapted ModuleAudio to accept the load, severals options to play, and unload FX.

***

### changelog v0.2.1
	
   * Code updated to sdl5_handout (ModuleFadeToBlack and some new adaptations).
   * Added circular scene switching (teamLogo and TitleScreen(WIP) -> lvl1 -> game over -> TitleScreen and so on).
   * Modified, but WIP moduleAudio with functions to load, unload and control music.
   * Every current scene loads their needed music song audio and unloads them.
   * Now we can close the game with mouse :).
   
***
   
### changelog v0.2

   * Changed ModuleParallax for ModuleBackground.
   * ModuleBackground contains:
	  * Functionality to scroll backgrounds with parameter camera speed simulating parallax profundity effect.
	  * Added ALL background logic and animations.
   * Modified ModuleRender with funcionality:
      * To flip textures.
      *	Optional parameter of parallax speed y.
   * Modified class animation: 
      * To accept parameter repeat, wich optional prevent cycling animations.
	  * Adapted the method pushback to reserve new rects with dynamic memory.
   * Added ModulePlayer with all the player movement logic and appropiate animations.

***   
 
### Changelog v0.1

   * Added provisional moduleParallax for scroll differents backgrounds at various speeds.
   * Added provisional moduleAudio wich loads one specific sound.
      * Functionality to playMusic with fadeIn, and on quit, fadeOut.
	  
