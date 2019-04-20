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


void runAllTests();
void isEmptyTest();


void sizeTest();

void addFrontTest();
void printMessage(int exepected, int actual,string nameOfTest, string possibleDiagnostic);

void addBackTest(); 
void searchTest(); 
void PercentageGiverToFile();
void constructorTest(); 

void PercentageGiver(); 
private:
int m_totalTests = 23; 
int m_correctTests =0; 
ofstream outFile; 






};
#endif
