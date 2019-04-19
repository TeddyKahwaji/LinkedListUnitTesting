#include "Test.h"
#include <iostream>


void Test::isEmptyTest()
{
    LinkedListOfInts myList;

    if(myList.size() !=0)
    {

      printMessage(0,myList.size(), "isEmptyTest");
      cout << endl;

    }
    else
    {
        printMessage(0,myList.size(), "isEmptyTest");
        cout << endl;
    }

    myList.addFront(4);
    if(myList.size() == 1)
    {

      printMessage(1,1, "isEmptyTest After Adding Front");
      cout << endl;

    }
    else
    {
        printMessage(1,myList.size(), "isEmptyTest After Adding Front");
        cout << endl;
    }

    LinkedListOfInts mySecond;
    mySecond.addBack(4);
    if(mySecond.size() == 1)
    {

      printMessage(1,mySecond.size(), "isEmptyTest After Adding back");
      cout << endl;

    }
    else
    {
        printMessage(1,mySecond.size(), "isEmptyTest After Adding Back");
        cout << endl;
    }

    mySecond.removeBack();

    if(mySecond.size() == 0)
    {

      printMessage(0,mySecond.size(), "isEmptyTest After Removing back");
      cout << endl;

    }
    else
    {
        printMessage(0,mySecond.size(), "isEmptyTest After Removing Back");
        cout << endl;
    }

}


void Test::printMessage(int expected, int actual, string nameOfTest)
{

    if(expected == actual)
    {
      cout << nameOfTest << ":" << " Passed" << endl;
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

void Test::runAllTests()
{
    isEmptyTest();
}
