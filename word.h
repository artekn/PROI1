#ifndef WORD_H
#define WORD_H
#include <iostream>

class Word
{
    private:
    std::string wordContent;
    int length;
    public:
    void lengthUpdate();
    int getLength(){return length;};
    std::string getWord(){return wordContent;};
    Word *next;
    Word *prev;
    Word();
    Word(std::string content);
    ~Word();
};

#endif // WORD_H
