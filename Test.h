#include "LinkedListOfInts.h"
#include <vector>
#include <string>
#ifndef TEST_H
#define TEST_H
using namespace std;


class Test
{

public:
Test(int size);
void isEmptyTest();

void printMessage(int exepected, int actual,string nameOfTest);

private:
int m_size;







};
#endif
