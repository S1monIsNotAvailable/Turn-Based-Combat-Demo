#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Character.h"

// Prints the current HP of both the player and the enemy, and enemy's fear points
static void printStatus(const Character& player, const Character& enemy) {
    std::cout << "\n=== Status ===\n";
    std::cout << player.getName() << " HP: " << player.getHP() << "\n";
    std::cout << enemy.getName() << " HP: " << enemy.getHP() << "\n";
    std::cout << "==============";
}

// Event for special dialogue
void showFearDialogue() {
    std::cout << "\n\n[SPECIAL DIALOGUE]\n\n";
    std::cout << "The goblin's eyes widen in terror. It falls on it's back, trembling with fear after so many of its attacks were blocked.\n";
    std::cout << "You drive your blade into the trembling goblin's chest. Its as easy as cutting through butter\n";
    std::cout << "Not satisfied yet, you head towards the nearby goblin camp.\n";
    std::cout << "You proceed to slaughter each goblin while easily swatting away any attack thrown at you.\n";
    std::cout << "The remaining goblins tremble as you approach them with a calmness that puts the fear of god in them.\n";
    std::cout << "The sounds ring in your head like a sweet symphony.\n";
    std::cout << "Sounds of flesh ripping. Bones crunching. The agonizing screams of goblins.\n";
    std::cout << "As the symphony comes to a close and the screaming stops.\n";
    std::cout << "You find yourself standing above a mountain of goblin corpses.\n";
    std::cout << "The approval of a divine being washes over you.\n";
    std::cout << "The killings you've committed in such droves has won you the favor of Bhaal, The God of Murder.\n";
    std::cout << "Uninterested in the words of an evil god. You ignore his praise and head back to the guild hall covered in blood and guts.\n";
    std::cout << "The sanguine display of your viscera-covered leather armour is enough proof to turn in for your quest.\n";
    std::cout << "Whispers and murmurs fill the air as word spreads of your singlehanded massacre of the entire goblin camp.\n";
    std::cout << "You earn a title amongst the other adventurers.\n";
    std::cout << "\nThe Slayer\n";
    std::cout << "\nTHE GOBLIN SLAYER\n";
    std::cout << "\nSLAYER ENDING\n";
}

int main() {
    
    // Create the player and enemy characters with name, HP, and attack power
    Character player("Hero", 30, 8);
    Character enemy("Goblin", 20, 6);

    std::cout << "Turn-based Combat Game!\n\n";
    std::cout << "Here's a little story to go along with this little project.\n";
    std::cout << "You are an adventurer who excitedly took their first quest of hunting a goblin.\n";
    std::cout << "I mean.... its just a goblin... how hard could it be?\n";
    std::cout << "And lucky you. You find a goblin that has strayed a little too far from its camp.\n";
    std::cout << "You boldly engage the goblin in battle.\n\n";
    printStatus(player, enemy);

    bool playerTurn = true; // Track whose turn it is: true = player, false = enemy
	bool endedByFear = false; // Track if the game ended due to fear dialogue

    // Main game loop: continues as long as both characters are alive
    while (player.isAlive() && enemy.isAlive()) {
        if (playerTurn) {
            // Player's turn: prompt for action
            std::cout << "\nWhat will you do?   (a)Attack, (b)Block, or (q)Quit: ";
            char choice;
            std::cin >> choice;
            if (choice == 'q') {
                // Player chooses to quit the game
                std::cout << "\nYou fled the battle... a battle with a mere goblin...\n";
                std::cout << "You walk into the guild hall with nothing to show for your assignment.\n";
                std::cout << "The whispers and gossip fill the air as other adventurers hear of your failure to even slay a goblin.\nA mere goblin...\n";
                std::cout << "The guild doesn't revoke your adventurer's crest. But the damage has already been done.\n";
                std::cout << "You are given a title amongst the adventurers.\n";
                std::cout << "\n'The Yellow Bellied Coward'.\n";
                std::cout << "\nCOWARD ENDING\n";
                break; // Break the loop and end the game with special dialogue
            }
            if (choice == 'a') {
                // Player attacks the enemy
                int dmg = player.attackTarget();
                std::cout << "\nYou attack the " << enemy.getName() << " for " << dmg << " damage!\n\n";
                enemy.takeDamage(dmg);
            }
            if (choice == 'b') {
                // Player blocks the enemy's attack
                player.setBlocking(true);
                enemy.addFearPoint();
                std::cout << "\nYou brace yourself and block the next attack!\n\n";
                if (enemy.getFearPoints() == 5) {
                    showFearDialogue();
					break; // Break the loop and end the game with special dialogue
                }
            }
            if (choice != 'a' && choice != 'q' && choice != 'b') {
                std::cout << "\nYou fumble your weapon. Skipping your turn.\n";
            }
        }
        else {
            // Enemy's turn: always attacks the player
            int dmg = enemy.attackTarget();
            if (player.isBlocking()) {
                std::cout << "\n" << enemy.getName() << " attacks, but you block all the damage!\n\n";
            } else {
                std::cout << "\n" << enemy.getName() << " attacks you for " << dmg << " damage!\n\n";
                player.takeDamage(dmg);
            }
            // Reset block after enemy's attack
            player.setBlocking(false);
        }
        // Print the updated status after each turn
        printStatus(player, enemy);
        // Switch turns
        playerTurn = !playerTurn;
    }

    // Game over messages based on who is still alive
    if (!player.isAlive()) {
        std::cout << "\n\nThe goblin's crude scimitar slips past your defenses and lands a lethal blow. Slicing into your neck.\n";
        std::cout << "Your body crumples to the ground as you feel the wet heat of blood leaking from your neck.\n";
        std::cout << "The world around you fades as your body grows cold\n";
        std::cout << "\nYOU PERISH\n";
        std::cout << "\nBAD ENDING\n";
    }
    else if (!enemy.isAlive()) {
        std::cout << "\n\nYou successfully slay the " << enemy.getName() << ".\n";
        std::cout << "You feel a twinge of guilt for ending a life. Even if its a goblin.\n";
        std::cout << "Nevertheless, you take its head as proof of completion of your quest and return to the guild hall.\n";
        std::cout << "You completed your first quest! This is only the beginning of your story!\n";
        std::cout << "\nBut alas... That is a tale for another time.\n";
        std::cout << "\nGOOD ENDING\n";
    }

    std::cout << "\nGame End. Thank you for playing! :)\n";
    return 0;
}