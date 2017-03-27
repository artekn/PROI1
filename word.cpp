#include "word.h"

Word::Word()
{
    this->next=NULL;
    this->prev=NULL;
    this->wordContent="";
    this->length=0;
    //ctor
}
Word::Word(std::string content)
{
    this->next=NULL;
    this->prev=NULL;
    this->wordContent=content;
    this->length=wordContent.size();
    //ctor
}
void Word::lengthUpdate()
{
    this->length=sizeof(this->wordContent);
}
Word::~Word()
{
    //dtor
}
