#include "menu.h"

Menu::Menu()
{
    //ctor
}
void Menu::displayMenu(setManager newManager)
{
    int option;
    std::string x,y;
    std::cout<<"Welcome to manager of sets of words"<<std::endl;
    while (true)
    {
        std::cout<<"MAIN MENU"<<std::endl;
        std::cout<<"---------"<<std::endl;
        std::cout<<"1. Add word"<<std::endl;
        std::cout<<"2. Add word to set"<<std::endl;
        std::cout<<"3. Delete word from set"<<std::endl;
        std::cout<<"4. The longest word"<<std::endl;
        std::cout<<"5. The shortest word"<<std::endl;
        std::cout<<"6. The longest word in set"<<std::endl;
        std::cout<<"7. The shortest word in set"<<std::endl;
        std::cout<<"8. Delete duplicates in set"<<std::endl;
        std::cout<<"9. Add set"<<std::endl;
        std::cout<<"10. Delete set"<<std::endl;
        std::cout<<"11. Show words in set"<<std::endl;
        std::cout<<"12. Intersection of sets (disabled)"<<std::endl;
        std::cout<<"13. Union of sets (disabled)"<<std::endl;
        std::cout<<"14. Exit"<<std::endl;
        std::cout<<"What do you want to do? Enter correct number"<<std::endl;
        std::cin>>option;
        if (std::cin.fail())
        {
            std::cout<<"Bad input"<<std::endl;
            return;
        }
        switch(option)
        {
            case 1:
            {
                system("cls");
                std::string x;
                std::cout<<"Type the word to be added: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                newManager.addWord(x);
            }
            break;

            case 2:
            {
                system("cls");
                printAllWords(newManager);
                std::cout<<"Enter word: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findWord(x)==NULL)
                {
                    std::cout<<"There is no word "<<x<<std::endl;
                    break;
                }
                printAllSets(newManager);
                std::cout<<"Enter set: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(y)==NULL)
                {
                    std::cout<<"There is no set "<<y<<std::endl;
                    break;
                }
                newManager.addWordToSet(x,y);
            }
            break;

            case 3:
            {
                system("cls");
                printAllSets(newManager);
                std::cout<<"Enter set: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)==NULL)
                {
                    std::cout<<"There is no set "<<x<<std::endl;
                    break;
                }
                printWordsInSet(newManager.findSet(x));
                std::cout<<"Enter word: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)->findWordInSet(y)==0)
                {
                    std::cout<<"There is no word "<<y<<" in this set."<<std::endl;
                    break;
                }
                newManager.deleteWordFromSet(x,y);
            }
            break;

            case 4:
            {
                system("cls");
                if(newManager.firstWord==NULL)
                {
                    std::cout<<"There are no words."<<std::endl;
                    break;
                }
                printWordsInSet(newManager.getLongest());
                getchar();
            }
            break;

            case 5:
            {
                system("cls");
                if(newManager.firstWord==NULL)
                {
                    std::cout<<"There are no words."<<std::endl;
                    break;
                }
                printWordsInSet(newManager.getShortest());
                getchar();
            }
            break;

            case 6:
            {
                system("cls");
                printAllSets(newManager);
                std::string x;
                std::cout<<"Name the set where to look for the longest word(s): ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if (newManager.findSet(x)==NULL)
                {
                    std::cout<<"Set like this doesn't exist."<<std::endl;
                    break;
                }
                if (newManager.findSet(x)->list[0]==NULL)
                {
                    std::cout<<"This is an empty set."<<std::endl;
                    break;
                }
                printWordsInSet(newManager.findSet(x)->getLongest());
            }
            break;

            case 7:
            {
                system("cls");
                printAllSets(newManager);
                std::string x;
                std::cout<<"Name the set where to look for the shortest word(s): ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if (newManager.findSet(x)==NULL)
                {
                    std::cout<<"Set like this doesn't exist."<<std::endl;
                    break;
                }
                if (newManager.findSet(x)->list[0]==NULL)
                {
                    std::cout<<"This is an empty set."<<std::endl;
                    break;
                }
                printWordsInSet(newManager.findSet(x)->getShortest());
            }
            break;

            case 8:
            {
                system("cls");
                if (newManager.firstWord==NULL)
                {
                    std::cout<<"There are no words."<<std::endl;
                    getchar();
                }
                else if (newManager.firstSet==NULL)
                {
                    std::cout<<"There are no sets."<<std::endl;
                    getchar();
                }
                else
                {
                    printAllSets(newManager);
                    std::cout<<"Enter set: ";
                    std::cin>>y;
                    std::cin.ignore(100,'\n');
                    if (newManager.findSet(y)==NULL)
                    {
                        std::cout<<"There is no set "<<y<<"."<<std::endl;
                        break;
                    }
                    printWordsInSet(newManager.findSet(y));
                    std::cout<<"Enter word: ";
                    std::cin>>x;
                    std::cin.ignore(100,'\n');
                    if(newManager.findWord(x)==NULL)
                    {
                        std::cout<<"There is no word "<<x<<std::endl;
                        break;
                    }
                    newManager.deleteDuplicatesInSet(x,y);
                }
            }
            break;

            case 9:
            {
                system("cls");
                std::string x;
                std::cout<<"Type the name of set to be added: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                newManager.addSet(x);
            }
            break;

            case 10:
            {
                system("cls");
                printAllSets(newManager);
                std::string x;
                std::cout<<"Name the set to be deleted: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)==NULL)
                {
                    std::cout<<"There is no set "<<x<<"."<<std::endl;
                    break;
                }
                newManager.deleteSet(x);
            }
            break;

            case 11:
            {
                system("cls");
                printAllSets(newManager);
                std::cout<<"Enter set name: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)==NULL)
                {
                    std::cout<<"There is no set "<<x<<"."<<std::endl;
                    break;
                }
                if(newManager.findSet(x)->list[0]==NULL)
                {
                    std::cout<<"There are no words in set "<<x<<"."<<std::endl;
                    break;
                }
                printWordsInSet(newManager.findSet(x));
            }
            break;

            case 12:
            {
                system("cls");
                std::cout<<"Enter first set name: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)==NULL)
                {
                    std::cout<<"There is no set "<<x<<"."<<std::endl;
                    break;
                }
                std::cout<<"Enter second set name: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(y)==NULL)
                {
                    std::cout<<"There is no set "<<y<<"."<<std::endl;
                    break;
                }
                //printSet((newManager.findSet(x))*(newManager.findSet(y)));
            }
            break;

            case 13:
            {
                system("cls");
                std::cout<<"Enter first set name: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(x)==NULL)
                {
                    std::cout<<"There is no set "<<x<<"."<<std::endl;
                    break;
                }
                std::cout<<"Enter second set name: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                if(newManager.findSet(y)==NULL)
                {
                    std::cout<<"There is no set "<<y<<"."<<std::endl;
                    break;
                }
                //printSet((newManager.findSet(x))+(newManager.findSet(y)));
            }
            break;

            case 14:
            {
                system("cls");
                std::cout<<"Goodbye";
                exit(0);
            }

            default:
            std::cout<<"There is no such an option"<<std::endl;
            getchar();
        }
        std::cout<<"For next activity click press enter";
        getchar();
        system("cls");
    }
}
void Menu::printWord(Word *word)
{
    std::cout<<word->getWord()<<std::endl;
}
void Menu::printSet(Set *set)
{
    std::cout<<set->getName()<<std::endl;
}
void Menu::printAllWords(setManager newManager)
{
    Word *tmp;
    tmp=newManager.firstWord;
    while(tmp)
    {
        printWord(tmp);
        tmp=tmp->next;
    }
    return;
}
void Menu::printAllSets(setManager newManager)
{
    Set *tmp;
    tmp=newManager.firstSet;
    while(tmp)
    {
        printSet(tmp);
        tmp=tmp->next;
    }
    return;
}
void Menu::printWordsInSet(Set* setToPrint)
{
    int i=0;
    if(setToPrint->getName()!="") std::cout<<"Words in "<<setToPrint->getName()<<" set:"<<std::endl;
    else std::cout<<"Words in requested set:"<<std::endl;
    while(setToPrint->list[i]!=NULL)
    {
        printWord(setToPrint->list[i]);
        i++;
    }
}
Menu::~Menu()
{
    //dtor
}
