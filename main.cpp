#include <iostream>
#include "word.h"
#include "set.h"
#include "setManager.h"
#include "menu.h"
#include "test.h"

int main()
{
    int op;
    std::cout<<"1 for test, other number to continue"<<std::endl;
    std::cin>>op;
    if (op==1)
    {
        Test test1;
        if(test1.testAll()==1) std::cout<<"ok"<<std::endl;
    }
    setManager newManager;
    Menu newMenu;
    newMenu.displayMenu(newManager);
    return 0;
}
