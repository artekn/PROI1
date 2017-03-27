#ifndef MENU_H
#define MENU_H
#include "setManager.h"


class Menu
{
    public:
    void displayMenu(setManager newManager);
    void printWord(Word *word);
    void printSet(Set *set);
    void printAllWords(setManager newManager);
    void printAllSets(setManager newManager);
    void printWordsInSet(Set *setToPrint);
    Menu();
    ~Menu();
};

#endif // MENU_H
