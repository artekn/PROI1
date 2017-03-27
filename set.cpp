#include "set.h"

Set::Set()
{
    this->next=NULL;
    this->prev=NULL;
    int i;
    for(i=0;i<20;i++) this->list[i]=0;
    //ctor
}
Set::Set(std::string userName)
{
    this->name=userName;
    this->next=NULL;
    this->prev=NULL;
    int i;
    for(i=0;i<20;i++) this->list[i]=0;

}
Set *Set::operator*(Set *setIn1)
{
    Set *inter;
    inter=new Set;
    this->sortList();
    setIn1->sortList();
    int i=0,j=0,k=0;
    while (this->list[i]!=NULL && setIn1->list[j]!=NULL)
    {
        if(strcmp(this->list[i]->getWord().c_str(),setIn1->list[j]->getWord().c_str())==0)
        {
            inter->list[k]=this->list[i];
            k++;
        }
        else if (strcmp(this->list[i]->getWord().c_str(),setIn1->list[j]->getWord().c_str())>0) j++;
        else i++;
    }
    return inter;
}
Set *Set::operator+(Set *setIn1)
{
    Set *uni;
    uni=new Set;
    this->sortList();
    setIn1->sortList();
    int i=0,j=0,k=0;
    while (this->list[i]!=NULL && setIn1->list[j]!=NULL)
    {
        if(strcmp(this->list[i]->getWord().c_str(),setIn1->list[j]->getWord().c_str())==0)
        {
            uni->list[k]=this->list[i];
            k++;
        }
        else if (strcmp(this->list[i]->getWord().c_str(),setIn1->list[j]->getWord().c_str())>0) j++;
        else i++;
    }
    return uni;
}
void Set::sortList()
{
    Word *tmp;
    tmp=new Word("eg");
    int i,j;
    for(i=0;this->list[i]!=NULL;i++)
    {
        for(j=0;this->list[i-1]!=NULL;j++ )
        {
            if((strcmp(this->list[j]->getWord().c_str(),this->list[j+1]->getWord().c_str()))>0)
            {
                tmp->getWord()=this->list[j]->getWord();
                this->list[j]->getWord()=this->list[j+1]->getWord();
                this->list[j+1]->getWord()=tmp->getWord();
            }
        }
    }
}
int Set::findWordInSet(std::string wordToFind)
{
    int i=0;
    while (this->list[i]!=NULL)
    {
        if(this->list[i]->getWord()==wordToFind) return 1;
        else i++;
    }
    return 0;
}
Set *Set::getLongest()
{
    Set *tempSet;
    tempSet=new Set;
    int maxLength, i, j, k;
    maxLength=0; i=0; j=0, k=0;;
    while (this->list[k]!=NULL)
    {
        if (this->list[k]->getLength()>maxLength)
        {
            for(j=0;j<=i;j++)
            {
                tempSet->list[j]=NULL;
            }
            i=0;
            tempSet->list[i]=this->list[k];
            maxLength=this->list[k]->getLength();
            i++;
            k++;
        }
        else if (this->list[k]->getLength()==maxLength)
        {
            tempSet->list[i]=this->list[k];
            i++;
            k++;
        }
        else k++;
    }
    return tempSet;
}
Set *Set::getShortest()
{
    Set *tempSet;
    tempSet=new Set;
    int minLength, i, j, k;
    minLength=100; i=0; j=0, k=0;;
    while (this->list[k]!=NULL)
    {
        if (this->list[k]->getLength()<minLength)
        {
            for(j=0;j<=i;j++)
            {
                tempSet->list[j]=NULL;
            }
            i=0;
            tempSet->list[i]=this->list[k];
            minLength=this->list[k]->getLength();
            i++;
            k++;
        }
        else if (this->list[k]->getLength()==minLength)
        {
            tempSet->list[i]=this->list[k];
            i++;
            k++;
        }
        else k++;
    }
    return tempSet;
}
Set::~Set()
{
//dtor
}
