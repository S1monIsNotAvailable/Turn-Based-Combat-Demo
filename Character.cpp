#include "Character.h"

// Constructor: initializes the character's name, HP, attack power, blocking state, and fear points.
Character::Character(const std::string& name, int hp, int attack)
    : name(name), hp(hp), attackPower(attack), blocking(false), fearPoints(0) {}

// Returns true if the character is still alive (HP > 0).
bool Character::isAlive() const {
    return hp > 0;
}

// Reduces the character's HP by the given damage amount.
// Ensures HP does not drop below 0.
void Character::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

// Returns the character's attack power (used as damage dealt).
int Character::attackTarget() const {
    return attackPower;
}

// Returns the character's name.
std::string Character::getName() const {
    return name;
}

// Returns the character's current HP.
int Character::getHP() const {
    return hp;
}

// Set blocking state (for player)
void Character::setBlocking(bool value) {
    blocking = value;
}

// Returns true if the character is in a blocking state.
bool Character::isBlocking() const {
    return blocking;
}

// Add a fear point (for enemy)
void Character::addFearPoint() {
    fearPoints++;
}

// Returns the number of fear points.
int Character::getFearPoints() const {
    return fearPoints;
}