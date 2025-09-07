#include <iostream>
#include <iomanip>
#include "cutee.h"
#include "t.codec.h"
using namespace std;
using namespace cutee;

// static vars initialization
CuteeTest* TestList::list[MAX_TEST_COUNT];
int TestList::list_idx = 1;

int main(int argc, char **argv) 
{

	TestList::list[TestList::list_idx] = new test_codec();
	TestList::list_idx++;

	Runner r(argc, argv);
	r.run();
}
