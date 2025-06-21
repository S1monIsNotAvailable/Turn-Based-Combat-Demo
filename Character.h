#pragma once
#include <string>

// The Character class represents a basic game character with a name, health points (HP), attack power, and (for enemies) fear points.
class Character {
public:
    // Constructor: initializes the character with a name, HP, and attack power.
    Character(const std::string& name, int hp, int attack);

    // Returns true if the character's HP is greater than 0.
    bool isAlive() const;

    // Reduces the character's HP by the specified damage amount.
    // HP will not go below 0.
    void takeDamage(int dmg);

    // Returns the character's attack power (damage dealt when attacking).
    int attackTarget() const;

    // Returns the character's name.
    std::string getName() const;

    // Returns the character's current HP.
    int getHP() const;

    // Block-related methods (for player)
    void setBlocking(bool value);
    bool isBlocking() const;

    // Fear point methods (for enemy)
    void addFearPoint();
    int getFearPoints() const;

    

protected:
    std::string name;   // The character's name
    int hp;             // The character's current health points
    int attackPower;    // The character's attack power
    bool blocking;      // True if the character is blocking this turn (used for player)
    int fearPoints;     // Number of times the enemy has been blocked (used for enemy)
};