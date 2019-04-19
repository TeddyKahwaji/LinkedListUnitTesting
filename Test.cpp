#include "Test.h"
#include <iostream>


void Test::isEmptyTest()
{
    LinkedListOfInts myList;

    if(myList.size() !=0)
    {

      printMessage(0,myList.size(), "isEmptyTest");

    }
    else
    {
        printMessage(0,myList.size(), "isEmptyTest");
    }



}


void Test::printMessage(int expected, int actual, string nameOfTest)
{

    if(expected == actual)
    {
      cout << nameOfTest << " : " << " passed" << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
    }
    else
    {
      cout << nameOfTest << " : " << " Error" << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
    }

}
