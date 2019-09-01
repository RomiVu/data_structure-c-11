#include <iostream>
#include <cstdlib>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <cassert>
#include <utility>// for std::swap  C++11
#include "seqlist.h"

namespace MyRandom
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	// std::mt19937 mersenne(static_cast<std::mt19937::result_type>(100));
}

static const int MaxSize = 1000;


void InitList(SeqList &L)
{
    L.data = new elemType[MaxSize];
    L.length = 0;
    L.capacity = MaxSize;
}

int Length(SeqList &L)
{
    return L.length;
}

int LocateElem(SeqList &L, elemType elem)
{
    for (int ii=0; ii<L.length; ++ii)
    {
        if (L.data[ii] == elem)
            return ii+1;
    }
    return 0;
}

elemType GetElem(SeqList &L, int index)
{
    if (index < 1 || index > L.length)
        exit(1); // 越界
    return L.data[index-1];
}

bool ListInsert(SeqList &L, int index, elemType elem)
{
    if (index < 1 || index > L.length + 1)
        return false; // 越界
    if (L.length >= L.capacity)
        return false;
    for (int ii=L.length; ii >= index; --ii)
        L.data[ii] = L.data[ii-1];

    L.data[index -1] = elem;
    ++L.length;
    return true;
}

bool ListDelete(SeqList &L, int index, elemType &elem)
{    
    if (index < 1 || index > L.length)
        return false; // 越界
    elem = L.data[index - 1];
    for (int ii=index; ii < L.length; ++ii)
        L.data[ii-1] = L.data[ii];
    --L.length;
    return true;
}

void PrintList(SeqList &L)
{
    std::cout << "SeqList length=" << L.length << " and capacity=" << L.capacity << std::endl;
    if (!isEmpty(L))
        {
        for (int ii=0; ii< L.length; ++ii)
        std::cout << L.data[ii] << ' ';
        std::cout << "\n\n";
        }
}

bool isEmpty(SeqList &L)
{
    if (L.length == 0)
        return true;
    return false;
}

void DestoryList(SeqList &L)
{
    delete [] L.data;
    L.capacity = 0;
    L.length = 0;
}

void ListDeleteMinElem(SeqList &L, elemType &a)
{
    assert(!(isEmpty(L)) && "SeqList is empty.");
    a = L.data[0];
    int index { 0 };

    for (int ii=1; ii<L.length; ++ii)
    {
        if (L.data[ii] < a)
        {
            a = L.data[ii];
            index = ii;
       }
    }
    L.data[index] = L.data[L.length - 1];
    --L.length;
}

void ListReversed(SeqList &L)
{
    assert(!(isEmpty(L)) && "SeqList is empty.");
    for (int ii=0; ii<(L.length/2); ++ii)
        std::swap(L.data[ii], L.data[L.length-ii-1]);
}

void ListDeleteAllx(SeqList &L, elemType elem)
{
    assert(!(isEmpty(L)) && "SeqList is empty.");
    int occurrence = 0;
    for (int ii=0;ii<L.length;++ii)
    {
        if (L.data[ii] == elem)
            {
            L.data[ii-occurrence] = L.data[ii+1];
            ++occurrence;
            }
        else
           L.data[ii-occurrence] = L.data[ii];   
    }
    L.length -= occurrence;
}

void ListDeleteRangexy(SeqList &L, elemType x, elemType y)
{
    assert(!(isEmpty(L)) && (x < y) && "SeqList is empty.");
    int occurrence = 0;
    for (int ii=0;ii<L.length;++ii)
    {
        if (L.data[ii] > x && L.data[ii] < y)
            {
            L.data[ii-occurrence] = L.data[ii+1];
            ++occurrence;
            }
        else
           L.data[ii-occurrence] = L.data[ii];   
    }
    L.length -= occurrence;
}


void ListDeleteDuplicate(SeqList &L)
{
   if(isEmpty(L))
       return;
    // for(int ii=0; ii<L.length; ++ii)
    // {   
    //     int occur=0;
    //     for(int jj=ii+1;jj<L.length;++jj)
    //     {
    //         if (L.data[jj] == L.data[ii])
    //         {
    //             ++occur;
    //             while (L.data[jj+occur] == L.data[ii] && (jj+occur) <L.length)
    //             {
    //                 ++occur;
    //             }
    //             L.data[jj] = L.data[jj+occur];
    //         }
    //         if (occur != 0)
    //             L.data[jj] = L.data[jj+occur];
    //     }
    // }
    // todo:
}

int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution<> die(min, max); // we can create a distribution in any function that needs it
	return die(MyRandom::mersenne); // and then generate a random number from our global generator
}

void ListSortedMerge(SeqList &L1, SeqList &L2)
{
    // L1 and L2 is sorted.
    SeqList mergedList;
    InitList(mergedList);

}