#include "Test.h"
#include <iostream>
#include <algorithm>



/*

Simply prints a message to terminal whether the test failed or passed and provides a possible diagonstic for test
Note: The if expected ==11 and actuall == 12 case is simply just used for formatting messages to terminal and not meant as a specific case to catch errors in testing.
*/

void Test::printMessage(int expected, int actual, string nameOfTest, string diagnostic)
{

    if(expected == actual)
    {
      cout << nameOfTest << ":" << " Passed" << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      m_correctTests++;
    }
    else if(expected == 11 && actual == 12)
    {
      cout << "Unit Testing for method: " << nameOfTest  << " will begin now" << endl;
      cout << "-----------------------------------------------------------------------";
      cout << endl;
    }
    else
    {
      cout << nameOfTest << ":" << " Failed" << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      outFile << "Error for Test: " << nameOfTest << endl;
      outFile << "Reasoning: " << diagnostic << endl << endl;

    }

}
/*
A series of tests to ensure each possibility of isEmpty is analyzed.
The isEmptyTest will test empty lists, fixed length lists, adding and removing from lists, etc.

*/
void Test::isEmptyTest()
{
    int falseyoTruey =0;
    printMessage(11,12,"EmptyTest Method","Ignore");
    LinkedListOfInts myList;


    if(myList.isEmpty() && myList.toVector().size()==0)
    {
      falseyoTruey = 1;
    }
    printMessage(1, falseyoTruey, "isEmptyTest for an empty list", "likely due to not accounting for edge case of an empty list or a nonfunctional constructor" );
    cout << endl;
    falseyoTruey =0;
    myList.addFront(4);
    myList.removeFront();
    if(myList.isEmpty() &&myList.toVector().size())
    {

    falseyoTruey = 1;

    }

    printMessage(1, falseyoTruey, "isEmptyTest after adding front and removing front", "likely due to not removing front properly");
    cout << endl;



    falseyoTruey =0;
    LinkedListOfInts mySecond;
    mySecond.addBack(4);
    mySecond.removeBack();

    if(mySecond.isEmpty() && mySecond.toVector().size()==0)
    {

      falseyoTruey =1;
    }


    printMessage(1, falseyoTruey, "isEmptyTest after adding back and immediately removing back", "Likely due to inability to remove back properly note that that isEmpty correctly returns true however when checking the vectors size it is still 1.This implies your removeBack is broken");
    cout << endl;



}
void Test::sizeTest()
{
  printMessage(11,12,"size Method", "ignore");
  LinkedListOfInts aList;
  printMessage(aList.toVector().size(),aList.size(), "Size after calling default constructor(emptyList)", "Likely due to not setting size to 0 in constructor definition");
  cout << endl;
  aList.addFront(3);

    printMessage(aList.toVector().size(),aList.size(), "Size after adding front to an empty list", "Likely due to a nonfunctional add front method");
    cout << endl;



  aList.addFront(3);
  printMessage(aList.toVector().size(), aList.size(),"Size after adding front to a list of size 1", "Likely due to a nonfunctional add front method");
  cout << endl;
  aList.removeFront();
  printMessage(aList.toVector().size(),aList.size(),"Size after removing Front from a list of size 2", "Likely due to a broken remove front method");
  cout << endl;

  LinkedListOfInts secondList;
  secondList.addBack(4);
  printMessage( secondList.toVector().size(),secondList.size(),"Size after adding back to an empty list", "Likely due to a broken add back method");
  cout << endl;
  secondList.addBack(5);
  printMessage(secondList.toVector().size(),secondList.size(), "Size after adding back twice", "Likely due to broken add back method");
  cout << endl;

  secondList.removeBack();
  printMessage( secondList.toVector().size(),secondList.size(),"Size after removing Back from a list of size 2" , "likely because remove back method is not functional");
  cout << endl;




}

void Test::addFrontTest()
{
  printMessage(11,12,"addFront Method","ignore");
  LinkedListOfInts T;
  srand (time(NULL));
  int randomValue = rand() % 10000 + 1; //  in the range 1 to 10000
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }

  T.addFront(randomValue);
  int previousValue = randomValue;
  printMessage( randomValue,T.toVector()[0], "Value at the front of the list after using add Front with Empty List", "likely because add front is not maintaining the positioning of list");
  cout << endl;
  //randomize again
  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addFront(randomValue);
  printMessage( randomValue,T.toVector()[0], "Value at the front of the list after using addFront with a list of size 1", "likely because add front is not maintaining the positioning of the list");
  cout << endl;

  printMessage( previousValue,T.toVector()[1], "Value at position 1 after adding front to a list of size 1(Order Check)", "likely because add front is compromising proper order of the list");
  cout << endl;

  for (int i =0; i<=10; i++)
  {
    randomValue = rand() % 10000 + 1;
  }
  T.addFront(randomValue);
  printMessage( previousValue,T.toVector()[2], "Value at position 2 after adding front to a list of size 2(Order Check)", "likely because function does not mainting proper ordering");
  cout << endl;
}


//redo this compeltely
void Test::addBackTest()
{
  printMessage(11,12,"addBack Method", "ignore");
  LinkedListOfInts T;
  srand (time(NULL));
  int randomValue = rand() % 10000 + 1; //  in the range 1 to 10000

  T.addBack(randomValue);

  printMessage(randomValue, T.toVector()[0], "Test ensuring value was correctly added to the back of an empty list", "likely due to error in add back method");
  cout << endl;
  int previous = randomValue;
  randomValue = rand() % 10000+1;
  T.addBack(randomValue);

  printMessage(randomValue, T.toVector()[T.toVector().size()-1], "Test ensuring value was correctly added to back of a list of size 1", "likely due to error in maintaining order after adding node back to list");
  cout << endl;

  printMessage(previous, T.toVector()[0], "Test ensuring the ordering was not compromised after adding back to list of size 1", "likely due to order being compromised by add back method. Ordering is not maintained");
  cout << endl;
}


void Test::searchTest()
{
  printMessage(11,12,"searchTest Method", "ignore");
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


  printMessage(1, falseyoTruey, "Search Test after adding back value of 1 to list (1 = true, 0 = false)", "Likely due to inability to traverse and find value within method. Could because getEntry is being used on wrong node");
  cout << endl;

    tester.addFront(10);
    if(!tester.search(10))
    {
      falseyoTruey =0;
    }
    printMessage(1, falseyoTruey, "Search Tester aftering adding a value of 10 to front of list (1 = true, 0 = false)", "likely either a broken add front method or inability to traverse and find proper node");
    cout << endl;
  if(!tester.search(52) )
  {
    falseyoTruey =0;
  }
  printMessage(0, falseyoTruey, "Search test after searching for a value not contained within list (1 = true, 0 = false)", "likely returning true after not finding the value in node");

  cout << endl;

  tester.addFront(12);
  tester.removeFront();
  if(!tester.search(12))
  {
    falseyoTruey =0;
  }
  printMessage(0, falseyoTruey, "Search test after adding front and immediately removing front value (1 = true, 0 = false)", "possibly a broken removeFront method or traversing is not done properly within search Method");
  cout << endl;

  tester.addBack(699);
  tester.removeBack();
  if(!tester.search(699))
  {
    falseyoTruey =0;
  }
  printMessage(0, falseyoTruey, "Search Test after adding back and immediately removing back value (1 = true, 0 = false)", "likely a broken remove back method or traversing is not done properly for search method");


  LinkedListOfInts empty;
  if(empty.search(3))
  {
    falseyoTruey = 1;
  }
  cout << endl;
  printMessage(0,falseyoTruey, "Search Test after searching an empty list (1=true,0=false)", "likely due to the fact the edge case of an empty case was not accounted for");
  cout << endl;
  PercentageGiverToFile();

}


void Test::constructorTest()
{
  outFile.open("bugs.txt");
  outFile << "Tests are complete! Results and diagnostics are shown below: " << endl << endl;

  printMessage(11,12,"Default Constructor ","ignore");
  LinkedListOfInts* hi = new LinkedListOfInts();

  printMessage(0, hi->toVector().size(), "Test ensuring that default constructor intializes list to size 0 with no contents", "likely because a size was not explicilty intialized in constructor definition");
  cout << endl;


  delete hi;
}

void Test::PercentageGiver()
{

  cout << endl << endl;
  double x = m_correctTests;
  double y = m_totalTests;
  double percentage = (x/y)* 100;


  cout << "Tests are complete! For indepth analysis please checkout bugs.txt file!" << endl;
  cout << "Statistics: " << endl;
  cout << "Total Tests completed: " << m_totalTests << endl;
  cout << "Tests passed: " << m_correctTests << endl;
  cout << "Tests failed: " << m_totalTests - m_correctTests << endl;
  cout << "Percentage: " << percentage << "%" << endl;


}
void Test::PercentageGiverToFile()
{
  outFile << endl << endl;
  double x = m_correctTests;
  double y = m_totalTests;
  double percentage = (x/y)* 100;


  outFile << "---------------------------------------------------------------------" << endl;
  outFile << "Statistics: " << endl;
  outFile << "Total Tests completed: " << m_totalTests << endl;
  outFile << "Tests passed: " << m_correctTests << endl;
  outFile << "Tests failed: " << m_totalTests - m_correctTests << endl;
  outFile << "Percentage: " << percentage << "%" << endl;
}
void Test::runAllTests()
{
    constructorTest();
    isEmptyTest();
    sizeTest();
    addFrontTest();
    addBackTest();

    searchTest();
    PercentageGiver();

}
