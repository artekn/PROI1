#include "test.h"

Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

bool Test::testAll()
{
    setManager testManager;
    if(testManager.addWord("a")==0) return 0;
    if(testManager.addWord("bb")==0) return 0;
    if(testManager.addWord("ccc")==0) return 0;
    if(testManager.addWord("d3d3")==0) return 0;
    if(testManager.addSet("a")==0) return 0;
    if(testManager.addSet("b")==0) return 0;
    if(testManager.addSet("c")==0) return 0;
    if(testManager.addSet("d")==0) return 0;
    if(testManager.addSet("e")==0) return 0;
    if(testManager.deleteSet("e")==0) return 0;
    if(testManager.addWordToSet("a","b")==0) return 0;
    if(testManager.addWordToSet("a","b")==0) return 0;
    if(testManager.addWordToSet("a","b")==0) return 0;
    if(testManager.addWordToSet("d3d3","b")==0) return 0;
    if(testManager.addWordToSet("x","b")==1) return 0;
    if(testManager.addWordToSet("a","d")==0) return 0;
    if(testManager.deleteWordFromSet("b","a")==0) return 0;
    if(testManager.getLongest()->list[0]->getWord()!="d3d3") return 0;
    if(testManager.getShortest()->list[0]->getWord()!="a") return 0;
    if(testManager.findSet("a")->getName()!="a") return 0;
    if(testManager.findSet("d")->getName()!="d") return 0;
    if(testManager.findWord("bb")->getWord()!="bb") return 0;
    if(testManager.findWord("ccc")->getWord()!="ccc") return 0;
    if(testManager.findSet("b")->getLongest()->list[0]->getWord()!="d3d3") return 0;
    if(testManager.findSet("b")->getShortest()->list[0]->getWord()!="a") return 0;
    return 1;
}
