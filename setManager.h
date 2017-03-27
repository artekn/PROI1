#ifndef SETMANAGER_H
#define SETMANAGER_H
#include <cstdlib>
#include <stdio.h>
#include "set.h"


class setManager
{
    public:
    Set *firstSet;
    Set *lastSet;
    Word *firstWord;
    Word *lastWord;
    Set *findSet(std::string setToFind);
    Word *findWord(std::string wordToFind);
    Set *getLongest();
    Set *getShortest();
    int addSet(std::string userName);
    int deleteSet(std::string userName);
    int addWord(std::string userWord);
    int addWordToSet(std::string wordToAdd, std::string setToBeUsed);
    int deleteWordFromSet(std::string setToDelete, std::string wordToDelete);
    int deleteDuplicatesInSet(std::string duplicatedWord, std::string neededSet);
    setManager();
    ~setManager();
};

#endif // SETMANAGER_H
