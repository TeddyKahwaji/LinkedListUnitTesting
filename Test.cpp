#include "Test.h"
#include <iostream>


void Test::isEmptyTest()
{
    LinkedListOfInts myList;

    if(myList.isEmpty())
    {

      printMessage(0,myList.toVector().size(), "isEmptyTest for Empty List");
      cout << endl;

    }
    else
    {
        printMessage(0,myList.toVector().size(), "isEmptyTest for Empty List");
        cout << endl;
    }

    myList.addFront(4);
    myList.removeFront();
    if(myList.isEmpty())
    {

      printMessage(0,myList.toVector().size(), "isEmptyTest After Adding Front and removing");
      cout << endl;

    }
    else
    {
        printMessage(0,myList.toVector().size(), "isEmptyTest After Adding Front and removing");
        cout << endl;
    }




    LinkedListOfInts mySecond;
    mySecond.addBack(4);
    mySecond.removeBack();
    if(mySecond.isEmpty())
    {

      printMessage(0,mySecond.toVector().size(), "isEmptyTest After Adding back and removing");
      cout << endl;

    }
    else
    {
        printMessage(0,mySecond.toVector().size(), "isEmptyTest After Adding Back and removing");
        cout << endl;
    }





}
void Test::sizeTest()
{
  LinkedListOfInts aList;
  printMessage(0,aList.toVector().size(), "Size after calling default constructor(emptyList)");
  cout << endl;
  aList.addFront(3);
  if(aList.size() ==1)
  {
    printMessage(1,aList.toVector().size(), "Size after adding front to an empty list");
    cout << endl;
  }
  else
  {
    printMessage(1,aList.toVector().size(), "Size after adding front to an empty list");
    cout << endl;
  }

  aList.addFront(3);
  printMessage(2,aList.toVector().size(), "Size after adding front to a list of size 1");
  cout << endl;
  aList.removeFront();
  printMessage(1,aList.toVector().size(), "Size after removingFront from a list of size 2");
  cout << endl;

  LinkedListOfInts secondList;
  secondList.addBack(4);
  printMessage(1,secondList.toVector().size(), "Size after adding back to an empty list");
  cout << endl;
  secondList.addBack(5);
  printMessage(2,secondList.toVector().size(), "Size after adding back twice");
  cout << endl;

  secondList.removeBack();
  printMessage(1,secondList.toVector().size(), "Size after removing Back from a list of size 2");
  cout << endl;




}

void Test::addFrontTest()
{
  LinkedListOfInts T;
  srand (time(NULL));
  int randomValue = rand() % 10000 + 1; //  in the range 1 to 10000
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }

  T.addFront(randomValue);
  int previousValue = randomValue;
  printMessage( randomValue,T.toVector()[0], "Value at the front of the list after using addFront with Empty List");
  cout << endl;
  //randomize again
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addFront(randomValue);
  printMessage( randomValue,T.toVector()[0], "Value at the front of the list after using addFront with a list of size 1");
  cout << endl;

  printMessage( previousValue,T.toVector()[1], "Value at position 1 after adding frontto a list of size 1(Order Check)");
  cout << endl;

  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addFront(randomValue);
  printMessage( previousValue,T.toVector()[2], "Value at position 2 after adding front to a list of size 2(Order Check)");
  cout << endl;
}


//redo this compeltely
void Test::addBackTest()
{
  LinkedListOfInts T;
  srand (time(NULL));
  int randomValue = rand() % 10000 + 1; //  in the range 1 to 10000
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }

  T.addBack(randomValue);
  int previousValue = randomValue;
  printMessage( randomValue,T.toVector()[0], "Value at the back of the list after using addBack with Empty List");
  cout << endl;
  //randomize again
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addBack(randomValue);
  printMessage( randomValue,T.toVector()[1], "Value at the back of the list after using addback with a list of size 1");
  cout << endl;

  printMessage( previousValue,T.toVector()[1], "Value at position 1 after adding back to a list of size 1(Order Check)");
  cout << endl;

  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addBack(randomValue);
  printMessage( previousValue,T.toVector()[T.toVector().size()-1], "Value at last position after adding back to a list of size 2(Order Check)");
  cout << endl;
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
    sizeTest();
    addFrontTest();
    addBackTest();
}
