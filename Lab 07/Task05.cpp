//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon) : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks." << endl;
    }

    virtual void defend() {
        cout << name << " defends." << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage) : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() {
        cout << name << " swings a " << weaponType << " dealing " << meleeDamage << " damage." << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power) : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() {
        cout << name << " uses magical barriors." << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() {
        cout << name << " fires with " << rangedAccuracy << " accuracy." << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agil) : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}

    void displayStats() {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior(13, "Thor", 10, 100, "Sword", 50, 30);
    Mage mage(24, "Martha", 12, 80, "Staff", 100, 40);
    Archer archer(58, "Leonard", 15, 90, "Bow", 20, 85);
    Rogue rogue(76, "Evian", 13, 85,"Dagger", 70, 95);

    warrior.attack();
    mage.defend();
    archer.attack();
    rogue.displayStats();
    
    return 0;
}