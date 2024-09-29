#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
public:
    const char* name;
    const char* story;
    int points;

    Character(const char* charName, const char* charStory)
        : name(charName), story(charStory), points(0) {}

    virtual void adventure() = 0;

    void fight() {
        srand(static_cast<unsigned>(time(0)));
        int playerChoice;

        cout << "Choose a number from 1 to 3: ";
        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Choose a number from 1 to 3." << endl;
            return;
        }

        int randomOutcome = rand() % 30;
        cout << "Random outcome: " << randomOutcome << endl;

        if (randomOutcome >= 10) {
            cout << "You chose " << playerChoice << ". You won!" << endl;
            points += 10;
        }
        else if (randomOutcome >= 5) {
            cout << "You chose " << playerChoice << ". You are injured!" << endl;
            points -= 5;
        }
        else {
            cout << "You chose " << playerChoice << ". You lost!" << endl;
            points -= 10;
            exit(0);
        }

        cout << "Points: " << points << endl;
    }
};

class Knight : public Character {
public:
    Knight() : Character("Knight", "You are a brave knight defending the kingdom from darkness.") {}

    void adventure() override {
        cout << "You chose the character: " << name << endl;
        cout << story << endl;
        char choice;
        cout << "You encounter a monster. Fight? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            fight();
            cout << "You saved the village from danger!" << endl;
            points += 10;
            cout << "Points: " << points << endl;
            cout << "For your bravery and responsibility, the villagers gifted you a sword! Take it? (y/n) ";
            cin >> choice;
            if (choice == 'y') {
                cout << "You have become stronger and more powerful!" << endl;
                points += 10;
                cout << "Points: " << points << endl;
                cout << "On your way home, you see a monster heading towards the village." << endl;
                cout << "Fight? (y/n)" << endl;
                cin >> choice;
                if (choice == 'y') {
                    cout << "Your strength with the new sword was weak because you didn't train." << endl;
                    cout << "You lost the battle." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "You walked past; the danger is behind you, but the village was destroyed." << endl;
                    points += 5;
                    cout << "Points: " << points << endl;
                }
            }
            else {
                cout << "You didn't take the sword; now dangers thirst for your blood!" << endl;
                cout << "As you were returning home, monsters surrounded you." << endl;
                points -= 20;
                cout << "Points: " << points << endl;
            }
        }
        else {
            cout << "You avoid the fight, but the village is destroyed." << endl;
            cout << "You are accused of cowardice..." << endl;
            points -= 10;
            cout << "Points: " << points << endl;

            cout << "You were humiliated, but at least you are safe.";
            cout << "On the way, you see a monster approaching you. y - fight, n - run away? (y/n) ";
            cin >> choice;
            if (choice == 'y') {
                fight();
                points += 10;
                cout << "Points: " << points << endl;
                cout << "Having escaped, you found a cave, enter? (y/n)" << endl;
                cin >> choice;
                if (choice == 'y') {
                    cout << "You were tired after the escape but remained alive." << endl;
                    points += 10;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "You were caught, and you lost." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
            }
            else {
                cout << "You were too weak for it." << endl;
                points -= 10;
                cout << "Points: " << points << endl;
            }
        }
    }
};

class Mage : public Character {
public:
    Mage() : Character("Mage", "You are a powerful mage studying ancient spells.") {}

    void adventure() override {
        cout << "You chose the character: " << name << endl;
        cout << story << endl;
        char choice;
        cout << "You find an ancient artifact. Take it? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            cout << "The artifact is cursed! You lose your magical powers." << endl;
            cout << "Now you need to find a way to lift the curse." << endl;
            points -= 10;
            cout << "Points: " << points << endl;
            cout << "You remember your friend who can solve these problems. Visit? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                cout << "He helped you regain only some of your powers." << endl;
                cout << "Suddenly, you see that a merchant is talking to your friend and wants to sell the cursed artifact." << endl;
                points += 5;
                cout << "Points: " << points << endl;
                cout << "Intervene? (y/n)";
                cin >> choice;
                if (choice == 'y') {
                    fight();
                    cout << "With your powers, you were able to defeat him, but before you could explain, ";
                    cout << "your friend was confused." << endl;
                    points += 10;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "Your friend was angry with you because you didn't tell him about this artifact." << endl;
                    points -= 20;
                    cout << "Points: " << points << endl;
                }
            }
            else {
                cout << "You couldn't regain your powers." << endl;
                points -= 10;
                cout << "Points: " << points << endl;
                cout << "Suddenly, you see that a merchant is talking to your friend and wants to sell the cursed artifact." << endl;
                cout << "Intervene? (y/n)";
                cin >> choice;
                if (choice == 'y') {
                    fight();
                    cout << "You lacked power in the battle; you lost." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "Your friend was angry with you because you didn't tell him about this artifact." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
            }
        }
        else {
            cout << "You avoid the trap and continue your journey." << endl;
            points += 10;
            cout << "Points: " << points << endl;
            cout << "You hear about a mysterious tower that holds a book capable of restoring your magical power." << endl;
            cout << "Go there? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                cout << "You head towards the tower. On the way, you encounter goblins attacking you." << endl;
                fight();
                points += 10;
                cout << "Points: " << points << endl;
                cout << "Fight or run away? (y/n): ";
                cin >> choice;
                if (choice == 'y') {
                    cout << "Using your remaining powers, you defeat the goblins but lose a lot of energy." << endl;
                    cout << "Finally, you reach the tower and find the book. It restores your powers." << endl;
                    cout << "Now you can continue your journey with full magical strength." << endl;
                    points += 10;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "You run away, but the goblins follow you. You lose the chance to reach the tower." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
            }
            else {
                cout << "You decided to refuse the tower and continued your path, but your powers remain unrestored." << endl;
                points -= 10;
                cout << "Points: " << points << endl;
            }
        }
    }
};

class Thief : public Character {
public:
    Thief() : Character("Thief", "You are a cunning thief, always ready for theft.") {}

    void adventure() override {
        cout << "You chose the character: " << name << endl;
        cout << story << endl;
        char choice;
        cout << "You see a rich merchant. Rob him? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            cout << "You steal gold, but the guards notice you. You run away." << endl;
            cout << "Now you are on the run, but with wealth." << endl;
            points += 20;
            cout << "Points: " << points << endl;
            cout << "After a while, you meet your old friend who advises you to hide. Do you agree? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                cout << "You hide successfully and get a chance to spend your wealth." << endl;
                points += 10;
                cout << "Points: " << points << endl;
            }
            else {
                cout << "You spend all your money on a grand feast." << endl;
                points -= 10;
                cout << "Points: " << points << endl;
            }
        }
        else {
            cout << "You avoid the robbery, but the guards notice you." << endl;
            points -= 10;
            cout << "Points: " << points << endl;
            cout << "You see a shadow behind you. Is it a guard or a thief? Investigate? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                cout << "You discovered a thief. He offered you to join him. Accept? (y/n): ";
                cin >> choice;
                if (choice == 'y') {
                    cout << "You became partners and shared wealth!" << endl;
                    points += 20;
                    cout << "Points: " << points << endl;
                }
                else {
                    cout << "You didn't trust him and lost a chance for wealth." << endl;
                    points -= 10;
                    cout << "Points: " << points << endl;
                }
            }
            else {
                cout << "You decide to run away but are caught by the guards." << endl;
                points -= 20;
                cout << "Points: " << points << endl;
            }
        }
    }
};

int main() {
    Knight knight;
    Mage mage;
    Thief thief;

    int choice;
    cout << "Выберите персонажа: 1 - Рыцарь, 2 - Маг, 3 - Вор: ";
    cin >> choice;

    if (choice == 1) {
        knight.adventure();
    }
    else if (choice == 2) {
        mage.adventure();
    }
    else if (choice == 3) {
        thief.adventure();
    }
    else {
        cout << "Неправильный выбор!" << endl;
    }

    return 0;
}
