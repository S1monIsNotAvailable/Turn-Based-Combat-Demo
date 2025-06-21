# Turn-Based Combat Demo (C++)

This is a simple C++ console game that demonstrates core turn-based combat logic with an added gameplay mechanic called **Fear Points**.

##  Features

- **Turn-based system**: The player and enemy take turns attacking or blocking.
- **Block mechanic**: Players can reduce damage and build up fear in the enemy.
- **Fear Points system**: After five successful blocks, the goblin becomes terrified and the game ends with a special alternate sequence.
- **Character class**: Encapsulates basic stats (HP, attack power) and state (blocking, fear).
- **No external libraries**: Runs on any standard C++ compiler.

##  How to Play

- Run the game in a terminal or console.
- Choose to:
  - `(a)` Attack the enemy
  - `(b)` Block the next attack
  - `(q)` Quit the game
- The enemy always attacks on its turn.
- Survive and reduce the goblin’s HP to 0 **or** trigger the fear ending by blocking five times.

##  How to Run

**Compile and run (Linux/macOS/WSL):**
```bash
g++ main.cpp Character.cpp -o combat && ./combat
