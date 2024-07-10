#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include "TimePerfTester.h"
#include "NewSort.h"
#include "IntroSort.h"
#include "TimSort.h"
using namespace std;

int main(int argc, char *argv[]) {
	TimePerfTester tester;
	tester.SetRandomTestcases(500, 100000, 100000);
	
	tester.TestAlgorithm(NewSort::Sort);
	cout << tester.GetResultAsStyledString("NewSort") << endl;
	
	tester.TestAlgorithm(IntroSort::Sort);
	cout << tester.GetResultAsStyledString("Intro Sort") << endl;
	
	tester.TestAlgorithm(TimSort::Sort);
	cout << tester.GetResultAsStyledString("Tim Sort") << endl;
	return 0;
}