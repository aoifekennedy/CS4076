#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "zorkul.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

class Character {
    friend class MainWindow;

private:
    string description;
    vector<Item> itemsInCharacter;
    float carriedWeight;
    int Health;
    int Lives;

public:
    Character();
    Character(string description);
    string shortDescription();
    string longDescription();
    vector<Item> viewItems();
    Item findItem(Item item);
    int findItemPos(Item item);
    void removeItem(Item item);
    string viewCharacterInfo();
    void addItem(string itemDescription);
    void addItem(Item *item);
    void addItem(Item &item);
    int getHealth();
    void setHealth(int Health);
    void decrementHealth();
    void incrementHealth();
    int getLives();
    void setLives(int Lives);
    void decrementLives();
};

#endif
