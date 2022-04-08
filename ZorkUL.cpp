#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
    srand(time(0));
}
void ZorkUL::createRooms() {
    Room *A, *B, *C, *D, *E, *F, *G, *H, *I, *J;

    A = new Room("A");
        //A->addItem(new Item("Bag", 1, 11));
    B = new Room("B");
        B->addItem(new Item("Apple", 3, 33));
    C = new Room("C");
        C->addItem(new Item("iPhone", 4, 44));
    D = new Room("D");
        D->addItem(new Item("Jacket", 5, 55));
    E = new Room("E");
    F = new Room("F");
        F->addItem(new Item("Shoes", 6, 66));
    G = new Room("G");
    H = new Room("H");
     H->addItem(new Item("Banana", 7, 77));
    I = new Room("I");
    J = new Room("J");
        J->addItem(new Item("Water", 8, 88));

//             (N, E, S, W)
    A->setExits(F, B, D, C);
    B->setExits(NULL, NULL, NULL, A);
    C->setExits(NULL, A, NULL, NULL);
    D->setExits(A, E, NULL, I);
    E->setExits(NULL, NULL, J, D);
    F->setExits(NULL, G, A, H);
    G->setExits(NULL, NULL, NULL, F);
    H->setExits(NULL, F, NULL, NULL);
    I->setExits(NULL, D, NULL, NULL);
    J->setExits(E, NULL, NULL, NULL);
    rooms.push_back(*A);
    rooms.push_back(*B);
    rooms.push_back(*C);
    rooms.push_back(*D);
    rooms.push_back(*E);
    rooms.push_back(*F);
    rooms.push_back(*G);
    rooms.push_back(*H);
    rooms.push_back(*I);
    rooms.push_back(*J);

    currentRoom = A;
}
string ZorkUL::printWelcome()
{
    return "Start \nInfo for Help\n" + currentRoom->longDescription();
}
string ZorkUL::printEnd()
{
    return "end";
}
string ZorkUL::printInfo()
{
    return " Welcome! The aim of this game is to get to the Winning Room without losing lives. The Winning Room changes each time the game is started, so every time you play it is a mystery. Good Luck! \n-Use North/East/South/West buttons to move in your desired direction. \n-Use Teleport to be teleported to a random room on the map.(Note: The Teleport command cannot be used to find the Winning Room!) \n-Press Map to reveal what rooms are in which direction. \n-There are items in certain rooms, you can double click to pick them up and double click to drop them again. If these items are food/water, by picking these up you will gain health!";
}
string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());

    if (currentRoom == nullptr) {
        return "error teleporting";
    } else {
        return currentRoom->longDescription();
    }
}

int ZorkUL::getrandomRoom()
{
    int randomRoom = rand() % rooms.size();

    //we do not want a random room = 1 as the game is over as it starts!
    if(randomRoom==0)
    {
        randomRoom = rand() % rooms.size();
    }

    return randomRoom;
}

string ZorkUL::map() {
    string output;
    output += "\n          [H] --- [F] --- [G]";
    output += "\n                      |         ";
    output += "\n                      |         ";
    output += "\n          [C] --- [A] --- [B]";
    output += "\n                      |         ";
    output += "\n                      |         ";
    output += "\n          [I] --- [D] --- [E]";
    output += "\n                                |         ";
    output += "\n                                |         ";
    output += "\n                               [J]         ";
    return output;
}
string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "It is not possible to proceed that way!";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
string ZorkUL::viewItems() {
    return currentRoom->displayItems();
}
Room ZorkUL::getCurrentRoom() {
    return *currentRoom;
}
