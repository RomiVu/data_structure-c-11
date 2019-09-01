#ifndef SEQLIST_H
#define SEQLIST_H

using elemType = int;

struct SeqList
{
   int length {};
   elemType *data;
   int capacity {};
};

void InitList(SeqList &L);
int Length(SeqList &L);
int LocateElem(SeqList &L, elemType elem);
elemType GetElem(SeqList &L, int index);
bool ListInsert(SeqList &L, int index, elemType elem);
bool ListDelete(SeqList &L, int index, elemType &elem);
void PrintList(SeqList &L);
bool isEmpty(SeqList &L);
void DestoryList(SeqList &L);
void ListDeleteMinElem(SeqList &L, elemType &a);
void ListReversed(SeqList &L);
void ListDeleteAllx(SeqList &L, elemType elem);
void ListDeleteRangexy(SeqList &L, elemType x, elemType y);
void ListDeleteDuplicate(SeqList &L);

void ListSortedMerge(SeqList &L1, SeqList &L2);

int getRandomNumber(int min, int max);

#endif