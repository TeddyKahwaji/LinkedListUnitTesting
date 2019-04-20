#include "Test.h"
#include <iostream>
#include <algorithm> 

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
        printMessage(0, myList.toVector().size(),"isEmptyTest for Empty List");
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
        printMessage(0,myList.toVector().size(), "isEmptyTest After Adding Back and removing");
        cout << endl;
    }





}
void Test::sizeTest()
{
  LinkedListOfInts aList;
  printMessage(0,aList.toVector().size(), "Size after calling default constructor(emptyList)");
  cout << endl;
  aList.addFront(3);
 
    printMessage(1,aList.toVector().size(), "Size after adding front to an empty list");
    cout << endl;
  


  aList.addFront(3);
  printMessage(2,aList.toVector().size(), "Size after adding front to a list of size 1");
  cout << endl;
  aList.removeFront();
  printMessage(1, aList.toVector().size(),"Size after removingFront from a list of size 2");
  cout << endl;

  LinkedListOfInts secondList;
  secondList.addBack(4);
  printMessage(1, secondList.toVector().size(),"Size after adding back to an empty list");
  cout << endl;
  secondList.addBack(5);
  printMessage(2,secondList.toVector().size(), "Size after adding back twice");
  cout << endl;

  secondList.removeBack();
  printMessage(1, secondList.toVector().size(),"Size after removing Back from a list of size 2");
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
  
  T.addBack(randomValue); 

  printMessage(randomValue, T.toVector()[0], "Test ensuring value was correctly added to the back of an empty list");
  cout << endl; 
  int previous = randomValue; 
  randomValue = rand() % 10000+1; 
  T.addBack(randomValue); 
  
  printMessage(randomValue, T.toVector()[T.toVector().size()-1], "Test ensuring value was correctly added to back of a list of size 1");
  cout << endl; 

  printMessage(previous, T.toVector()[0], "Test ensuring the ordering was not compromised after adding back to list of size 1"); 
  cout << endl; 
}


void Test::searchTest() 
{
  int falseyoTruey = 0;
  LinkedListOfInts tester; 
  for (int i =1; i<=10; i++)
  {
    tester.addBack(i);
  }

  if(tester.search(1))
  {
    falseyoTruey = 1;
  }

 
  printMessage(1, falseyoTruey, "Search Test after adding back value of 1 to list (1 = true, 0 = false)"); 
  cout << endl; 

    tester.addFront(10); 
    if(!tester.search(10))
    {
      falseyoTruey =0; 
    }
    printMessage(1, falseyoTruey, "Search Tester aftering adding a value of 10 to front of list (1 = true, 0 = false)");
    cout << endl; 
  if(!tester.search(52) )
  {
    falseyoTruey =0;
  }
  printMessage(0, falseyoTruey, "Search test after searching for a value not contained within list (1 = true, 0 = false)");

  cout << endl; 

  tester.addFront(12); 
  tester.removeFront(); 
  if(!tester.search(12))
  {
    falseyoTruey =0; 
  }
  printMessage(0, falseyoTruey, "Search test after adding front and immediately removing front value (1 = true, 0 = false)");
  cout << endl; 

  tester.addBack(699); 
  tester.removeBack(); 
  if(!tester.search(699))
  {
    falseyoTruey =0; 
  }
  printMessage(0, falseyoTruey, "Search Test after adding back and immediately removing back value (1 = true, 0 = false)");
  
}
void Test::runAllTests()
{
    isEmptyTest();
    sizeTest();
    addFrontTest();
    addBackTest();
    searchTest(); 
}
