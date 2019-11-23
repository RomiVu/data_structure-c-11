#ifndef CHAPTER1_H
#define CHAPTER1_H
#include <vector> 

using namespace std;

// delete duplicate elements in vector
void deleteDuplicates(vector<int> &v);
void deleteDuplicatesUnsorted(vector<int> &v);

// delete some specific elements in vector
void deleteSpecific(vector<int> &v, int target);
void deleteRangeFmTo(vector<int> &v, int low, int high);

// merge mulit sorted vector into one vector
vector<int> mergeTwoSorted(vector<int> &v1, vector<int> &v2); 
vector<int> mergeKSorted(vector<vector<int>> &v); 

// reverse vector 
void reverseOrder(vector<int> &v, int front, int end);
void reverseTwoVector(vector<int> &v, int n, int m);

// find specific element; if found then insert.
int findAndInsert(vector<int> &v, int target); 

// get median of sorted array
double getMedianOfArray(vector<int> &v1, vector<int> &v2);
double getMedianOfArrayUnsorted(vector<int> &v, int start, int end);
int findKthLarge(vector<int> &v, int k, int start, int end);


// different kinds of sorting 
void quickSort(vector<int> &v, int start, int end); // O(nlog(n))

#endif