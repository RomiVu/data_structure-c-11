#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    int maxSubsequence_n3(std::vector<int>& nums);
    int maxSubsequence_n2(std::vector<int>& nums);
    int maxSubsequence_newn(std::vector<int>& nums);
    int maxSubsequence_n(std::vector<int>& nums);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void printListNode(ListNode* lst);
    int lengthOfLongestSubstring(std::string s);
    std::string longestPalindrome(std::string s);
    std::string longestPalindrome_dp(std::string s); // to be continued
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
};

template <typename Comparable>
int binarySearch(const std::vector<Comparable>& v, const Comparable& t)
 {
 	int start=0, end=v.size()-1;
 	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(v[mid] > t)
			end = mid-1;
		else if (v[mid] < t)
			start = mid +1;
		else
			return mid;
	}

	return -1;
}

std::vector<int> standUpCallM(int players, int num);

#endif