#include "tools.h"
#include "chapter1.h"
#include <cstdio>
#include <vector>

int main(int argc, char const *argv[])
{
	vector<int> v {1,2,3,4,5,61,71,81,91};

    printf("find index : %d\n", findAndInsert(v, 5));


	CloseWindow();
	return 0;
}