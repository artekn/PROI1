#ifndef SET_H
#define SET_H
#include <string.h>
#include <cstring>
#include "word.h"

class Set
{
    private:
    std::string name;
    public:
    Word *list[20];
    Set *next;
    Set *prev;
    Set();
    Set(std::string userName);
    ~Set();
    void sortList();
    std::string getName(){return name;};
    int findWordInSet(std::string wordToFind);
    Set *operator*(Set *setIn1);
    Set *operator+(Set *setIn1);
    Set *getLongest();
    Set *getShortest();
};

#endif // SET_H
