# Classic Bomberman game
## Task
**Implement next variations of the game:**
* Game for 2 players on 1 device.
* Game against computer.

**Game should comply with this interface:**
- `Load map levels` from the pakage.
- Players can pick up configurable `bonuses` from the ground(increasing flame power, additional bombs, speed increase, set off bombs on distance).
- `Saving the best score` to the leaderboards.

**There can we use polymorphism?:**
* Managing players: local player, AI(different variations).
* User interface: console, ncurses, SDL OpenGl, etc .
* Effects of bonuses: flame power increase, additional bombs, etc.

**For more information:**
* https://en.wikipedia.org/wiki/Bomberman

## Specification
We will be implementing a classic bomberman game. User interface allows to choose between singleplayer(game against computer)
and multiplayer(game on one device for at least 2 players). At the beginning of the game each player has 1 bomb, which is replenished after each detonation.
However, for increasing a probability of winning, players are recommended to collect bonuses, which are randomly scattered across the map [Bonuses llist](#task).
In singleplayer main goal is to kill all monsters by placing down and detonating bombs,
after that, player will be advanced to the next level. In multiplayer the winner is decided by the last one standing alive. 





* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
This project is simple Lorem ipsum dolor generator.
	

	
## Setup
To run this project, install it locally using npm:

```
$ cd ../lorem
$ npm install
$ npm start
```

![This is an image](/assets/README_assets/readme_bomber.png)
