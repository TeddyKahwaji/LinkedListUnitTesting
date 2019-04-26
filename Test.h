#include "LinkedListOfInts.h"
#include <vector>
#include <string>
#include <fstream>
#ifndef TEST_H
#define TEST_H
using namespace std;


class Test
{

public:

//Simply a method that runs each test to terminal.
void runAllTests();
//Test to ensure that LinkedList is able to detect when length is at size 0
void isEmptyTest();

// test to ensure that the size provided by the linked list is correct; this is compared to the linked lists to vector method.
void sizeTest();


//Test to ensure linked list is adding to the front of the list without compromising order. 
void addFrontTest();


//Simply prints message to terminal screen and diagnostics to file
void printMessage(int exepected, int actual,string nameOfTest, string possibleDiagnostic);

//test to ensure that add back methods works and does not compromise the ordering of the list. 

void addBackTest();
//Test to ensure that the correct boolean value is being returned when detecting for a value in a list. 
void searchTest();
//Simply gives results of tests to file.
void PercentageGiverToFile();
//Tests that constructor is intializing properly.
void constructorTest();
//Tests for memory leak 
void destructorTest(); 
//Test to ensure the value being removed is at the back and does not compromise ordering of list. 
void removeBackTests(); 
//Test to ensure the value being removed is at the front and does not compromise ordering of list. 
void removeFrontTests(); 
//simply prints results to terminal. 
void PercentageGiver();
private:
int m_totalTests = 32;
int m_correctTests =0;
ofstream outFile;






};
#endif
