#include "seqlist.h"

int main()
{
    SeqList test;
    InitList(test);
    elemType a {1};
    elemType b {1000};

    for (int ii=0; ii< 15; ++ii)
    {
    ListInsert(test, 1, getRandomNumber(1, 10));
    }

    PrintList(test);
    
    ListDeleteDuplicate(test);
    
    PrintList(test);

    DestoryList(test);
    return 0;
}