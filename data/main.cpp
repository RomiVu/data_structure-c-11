#include "test.h"
#include "tools.h"
#include "solution.h"
#include "matrix.h"
#include "linklist.h"
#include "tree.h"
#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>


enum string_code
{
	sPrint,
	sDelete,
	sInsertHead,
	sInsertTail,
	sGetLength,
	sExit,
	sUnknown
};

string_code hashit (const std::string &inputString)
{
	if (inputString == "print") return sPrint;
	if (inputString == "delete") return sDelete;
	if (inputString == "inserthead") return sInsertHead;
	if (inputString == "inserttail") return sInsertTail;
	if (inputString == "getlength") return sGetLength;
	if (inputString == "exit") return sExit;
	return sUnknown;
}

int main()
{
    std::vector<int> num1 {1,3,5,7,9};
    std::vector<int> num2 {2,4,6,8,10};
    Solution s;
    s.findMedianSortedArrays(num1, num2);
	/*
	sort algorithm
	std::vector<int> v {53,17,78,9,45,65,87,32};

    int i =0;
    while (i < 8)
    {
	    v.push_back(getRandomNumber(-30, 30));
	    ++i;
    }
    std::vector<int> v1 = v;
    std::vector<int> v2 = v;
    std::vector<int> v3 = v;

    printVector(v);


    Timer clock;
    quickSort(v, 0, v.size()-1);
    printf("\nquicksort sort used %0.5f seconds...\n",clock.interval());
    printVector(v);

    bubbleSort(v1);
    printf("\nbubbleSort sort used %0.5f seconds...\n",clock.interval());
    printVector(v1);

    selectSort(v2);
    printf("\nselect basic sort used %0.5f seconds...\n",clock.interval());
    printVector(v2);

    heapSort(v3);
    printf("\ninsert build max heap sort used %0.5f seconds...\n",clock.interval());
    printVector(v3);
    */


    /*
    Node head1;
    Node head2;

    for(int i=0; i<10; i++)
    {
    	Node *data1 = new Node(getRandomNumber(1, 500));
    	headInsert(&head1, data1);
    	Node *data2 = new Node(getRandomNumber(500, 1000));
    	headInsert(&head2, data2);
    }

    pirntList(head1);
    pirntList(head2);


    while(true)
    {
    	std::cout << "\nInput your instruction: print; delete; inserthead; inserttail; getlength\n";
    	std::string instruction;
    	std::getline(std::cin, instruction);
    	// std::cin >> instruction;
    	switch(hashit(instruction))
    	{
    		case sPrint: 
    		{
    			pirntList(head1); 
    			break;
    		}
    		case sDelete: 
    		{
    			int index;
    			std::cout << "delte which position element: \n"; 
    			std::cin >> index;
    			deletebyIndex(head1, index); 
    			break;
    		}
    		case sInsertHead:
    		{
    			int value;
    			std::cout << "head insert which integer element: \n";
    			std::cin >> value;
    			Node *data = new Node(value);
    			headInsert(&head1, data);
    			pirntList(head1); 
    			break;
    		}
    		case sInsertTail:
    		{
    			int value;
    			std::cout << "tail insert which integer element: \n";
    			std::cin >> value;
    			Node *data = new Node(value);
    			tailInsert(&head1, data);
    			pirntList(head1);
    			break;
    		}
    		case sGetLength:
    		{
				printf("the linkedlist length is %d\n", getLength(head1));
				break;			
    		}
    		case sExit:
    		    return 0;
    		default:
    		    std::cout << '\n';
    	}
    }
    */

	CloseWindow();
    return 0;
}