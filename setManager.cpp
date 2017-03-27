#include "setManager.h"

setManager::setManager()
{
    this->firstSet=NULL;
    this->lastSet=NULL;
    this->firstWord=NULL;
    this->lastWord=NULL;
    //ctor
}
Set *setManager::findSet(std::string setToFind)
{
    Set *foundSet, *notFoundSet;
    foundSet=new Set;
    foundSet=firstSet;
    notFoundSet=NULL;
    while (foundSet!=NULL)
    {
        if(foundSet->getName()==setToFind) return foundSet;
        else foundSet=foundSet->next;
    }
    return notFoundSet;
}
Word *setManager::findWord(std::string wordToFind)
{
    Word *foundWord, *notFoundWord;
    foundWord=new Word;
    foundWord=firstWord;
    notFoundWord=NULL;
    while (foundWord!=NULL)
    {
        if(foundWord->getWord()==wordToFind) return foundWord;
        else foundWord=foundWord->next;
    }
    return notFoundWord;
}
Set *setManager::getLongest()
{
    Set *tempSet;
    Word *tempWord;
    int maxLength, i, j;
    tempSet=new Set;
    tempWord=firstWord;
    maxLength=0; i=0;
    while (tempWord!=NULL)
    {
        if (tempWord->getLength()>maxLength)
        {
            for(j=0;j<=i;j++)
            {
                tempSet->list[j]=NULL;
            }
            i=0;
            tempSet->list[i]=tempWord;
            maxLength=tempWord->getLength();
            i++;
            tempWord=tempWord->next;
        }
        else if (tempWord->getLength()==maxLength)
        {
            tempSet->list[i]=tempWord;
            i++;
            tempWord=tempWord->next;
        }
        else tempWord=tempWord->next;
    }
    return tempSet;
}
Set *setManager::getShortest()
{
    Set *tempSet;
    Word *tempWord;
    int minLength, i, j;
    tempSet=new Set;
    tempWord=firstWord;
    minLength=100; i=0;
    while (tempWord!=NULL)
    {
        if (tempWord->getLength()<minLength)
        {
            for(j=0;j<=i;j++)
            {
                tempSet->list[j]=NULL;
            }
            i=0;
            tempSet->list[i]=tempWord;
            minLength=tempWord->getLength();
            i++;
            tempWord=tempWord->next;
        }
        else if (tempWord->getLength()==minLength)
        {
            tempSet->list[i]=tempWord;
            i++;
            tempWord=tempWord->next;
        }
        else tempWord=tempWord->next;
    }
    return tempSet;
}
int setManager::addSet(std::string userName)
{
    Set *newSet;
    newSet=new Set(userName);
    if(firstSet==NULL)
    {
        firstSet=newSet;
        lastSet=newSet;
        newSet->next=NULL;
        newSet->prev=NULL;
    }
        else
        {
            lastSet->next=newSet;
            newSet->next=NULL;
            newSet->prev=lastSet;
            lastSet=newSet;
        }
    return 1;
}
int setManager::deleteSet(std::string userName)
{
    Set *tmp;
    tmp=new Set;
    tmp=findSet(userName);
    if (tmp==firstSet)
    {
        if(tmp->next==NULL)
        {
            firstSet=NULL;
            lastSet=NULL;
        }
        else
        {
        firstSet=tmp->next;
        firstSet->prev=NULL;
        }
    delete tmp;
    return 1;
    }
    else if (tmp==lastSet)
    {
        lastSet=tmp->prev;
        lastSet->next=NULL;
        delete tmp;
        return 1;
    }
    else
    {
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        delete tmp;
        return 1;
    }
}
int setManager::addWord(std::string userWord)
{
    Word *newWord;
    newWord=new Word(userWord);
    if(firstWord==NULL)
    {
        firstWord=newWord;
        lastWord=newWord;
        newWord->next=NULL;
        newWord->prev=NULL;
    }
        else
        {
            lastWord->next=newWord;
            newWord->next=NULL;
            newWord->prev=lastWord;
            lastWord=newWord;
        }
    return 1;
}
int setManager::addWordToSet(std::string wordToAdd, std::string setToBeUsed)
{
    int i;
    Word *tempWord;
    tempWord=new Word;
    tempWord=firstWord;
    Set *tempSet;
    tempSet=new Set;
    tempSet=findSet(setToBeUsed);
    while(tempWord!=NULL)
        {
            if(tempWord->getWord()==wordToAdd)
            {
                for(i=0;tempSet->list[i]!=NULL;i++);
                tempSet->list[i]=tempWord;
                return 1;
            }
            else tempWord=tempWord->next;
        }
}
int setManager::deleteWordFromSet(std::string setToDelete, std::string wordToDelete)
{
    int i=0,j;
    while(findSet(setToDelete)->list[i]!=NULL)
    {
        if(findSet(setToDelete)->list[i]->getWord()==wordToDelete)
        {
            for (j=i;findSet(setToDelete)->list[j+1]!=NULL;j++)
            {
                findSet(setToDelete)->list[j]=findSet(setToDelete)->list[j+1];
            }
        findSet(setToDelete)->list[j]=NULL;
        return 1;
        }
    i++;
    }
    return 0;
}
int setManager::deleteDuplicatesInSet(std::string duplicatedWord, std::string neededSet)
{
    int i=0, j, k=0;
    while(findSet(neededSet)->list[i]!=NULL)
    {
        if(findSet(neededSet)->list[i]->getWord()==duplicatedWord)
        {
            k++;
            if (k>1)
            {
                for (j=i;findSet(neededSet)->list[j+1]!=NULL;j++)
                {
                    findSet(neededSet)->list[k]=findSet(neededSet)->list[k+1];
                }
            findSet(neededSet)->list[j]=NULL;
            }
        }
    i++;
    }
    return 1;
}
setManager::~setManager()
{
    //dtor
}
