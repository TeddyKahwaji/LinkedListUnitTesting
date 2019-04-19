#include "Test.h"
#include <iostream>


void Test::isEmptyTest()
{
    LinkedListOfInts myList;

    if(myList.isEmpty())
    {

      printMessage(0,myList.size(), "isEmptyTest after calling default constructor: ");
      cout << endl;

    }
    else
    {
        printMessage(0,myList.size(), "isEmptyTest");
        cout << endl;
    }

    myList.addFront(4);
    myList.removeFront();
    if(myList.isEmpty())
    {

      printMessage(0,myList.size(), "isEmptyTest After Adding Front and removing");
      cout << endl;

    }
    else
    {
        printMessage(0,myList.size(), "isEmptyTest After Adding Front and removing");
        cout << endl;
    }




    LinkedListOfInts mySecond;
    mySecond.addBack(4);
    mySecond.removeBack();
    if(mySecond.isEmpty())
    {

      printMessage(0,mySecond.size(), "isEmptyTest After Adding back and removing");
      cout << endl;

    }
    else
    {
        printMessage(0,mySecond.size(), "isEmptyTest After Adding Back and removing");
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
      cout << nameOfTest << ":" << " Failed" << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
    }

}

void Test::runAllTests()
{
    isEmptyTest();
}
