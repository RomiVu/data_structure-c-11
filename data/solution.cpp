#include "solution.h"
#include <iostream>
#include <unordered_map>
#include <algorithm> // for std::sort
#include <queue>
#include <unordered_set>



std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) 
{
	std::unordered_map<int, int> mapping;
	std::vector<int> result;

	for (int i=0; i<nums.size(); i++) 
	{
		int numberToFind = target - nums[i];
		// std::cout << "now at " << i << " and value is " << nums[i] << "  " << numberToFind <<std::endl;
		if (mapping.find(nums[i]) != mapping.end())
		{
			result.push_back(nums[mapping[numberToFind]]);
			result.push_back(nums[i]);
			// std::cout << "now at " << i << std::endl;
			return result;
		}
		mapping[numberToFind] = i;
	}

// std::cout << "hash table size is " << mapping.size() << std::endl;
// std::cout << "mapping contains:";
//    for ( auto it = mapping.begin(); it != mapping.end(); ++it )
//        std::cout << " " << it->first << ":" << it->second;
//    std::cout << std::endl;

	return result;
}


int Solution::maxSubsequence_n3(std::vector<int>& nums)
{
	int rslt=0;
	for(int i=0; i<nums.size(); i++)
		for(int j=i; j<nums.size(); j++)
		{
			int temp =0;
			for(int k=i; k<=j; k++)
			{
				temp += nums[k];
			}
			if(temp > rslt)
				rslt = temp;
		}
	std::cout << "n3 largest subsequence sum is " << rslt << std::endl;
	return rslt;
}


int Solution::maxSubsequence_n2(std::vector<int>& nums)
{
	int rslt=0;
	for(int i=0; i<nums.size(); i++)
	{
		int temp =0;
		for(int j=i; j<nums.size(); j++)
		{
			temp += nums[j];
			if(temp > rslt)
				rslt = temp;
		}
	}
	std::cout << "n2 largest subsequence sum is " << rslt << std::endl;
	return rslt;
}

 int Solution::maxSubsequence_n(std::vector<int>& nums)
 {
 	int max = 0;
 	std::unordered_map<int, int> tail_mapping;
 	for(int i=0; i<nums.size(); i++)
 	{
 		if (nums[i] > 0)
 		{
 			tail_mapping[i] = nums[i];
 			if (max < nums[i])
 				max = nums[i];
		}
 	 	if (tail_mapping.find(i-1) != tail_mapping.end())
 	 	{
 	 		int temp = tail_mapping[i-1] + nums[i];
 	 		if (temp > 0)
 	 		    tail_mapping[i] = temp;
 	 		if(temp > max)
 	 			max = temp;
        }
    }

	std::cout << "n largest subsequence sum is " << max << std::endl;

	return max;
}


int Solution::maxSubsequence_newn(std::vector<int>& nums)
 {
 	int max = 0, temp = 0;

 	for(int i=0; i<nums.size(); i++)
 	{
 		temp += nums[i];
 		if (temp > max)
 			max = temp;
 		else if(temp < 0)
 			temp =0;
 	}
	std::cout << "new n largest subsequence sum is " << max << std::endl;

	return max;
}


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{

	ListNode rslt {0}, *p = &rslt;
	
	int carry = 0;

	while(l1 || l2 || carry)
	{
		int sum = (l1 ? l1->val : 0) +  (l2 ? l2->val : 0) + carry;
		p->next =  new ListNode {sum % 10};

		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
		carry = sum / 10;
		p = p->next;
	}
	return rslt.next;

}


void Solution::printListNode(ListNode* lst)
{
	std::cout << "ListNode is ";
	while (lst!=nullptr)
    {
    	std::cout << lst->val << ' ';
    	lst = lst->next;
    }
    std::cout << '\n';
}

int Solution::lengthOfLongestSubstring(std::string s)
{
	std::unordered_set<char> seen_chars;
	std::queue<char> q;
	int max = 0;

	for (auto chr : s)
	{
		q.push(chr);

		if (seen_chars.find(chr) != seen_chars.end())
		{	
			while (q.front() != chr)
				q.pop();
			q.pop();
		}
		else
			seen_chars.insert(chr);

		max = (q.size() > max ) ? q.size() : max;

	}

	std::cout << "1: " << max <<std::endl;

    std::vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i=0; i!=s.length(); i++) 
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }

    std::cout << "2: " << maxLen << std::endl;

	return max;
}


std::string Solution::longestPalindrome(std::string s)
{
	if (s.size() <= 1) return s;
	
	std::string rslt {};

	for (int i=0; i<s.size();i++)
	{
		int j = 1;
		while((i-j)>=0 && (i+j)<s.size())
			if (s[i-j] == s[i+j])
			{
				rslt = ((1+2*j) > rslt.size()) ? s.substr(i-j, 1+2*j) : rslt;
				j++;
		    }
		    else
		    	break;
	}
	std::cout << "final rslt is " << rslt << std::endl;
	return rslt;
}

bool isPalindrome(std::string s, int start, int end, std::string &rslt)
{
	if (start == end)
	{
		// std::cout << "final rslt is " << start << ' ' << end << std::endl;
		rslt = s.substr(start, end);
		return true;
	}
	if (s[start] == s[end] && start == (end - 1))
	{	
		// std::cout << "final rslt is " << start << ' ' << end << std::endl;
		rslt = s.substr(start, end);
		return true;
	}
	if (s[start] == s[end] && isPalindrome(s, start+1, end-1, rslt))
	{	
		// std::cout << "final rslt is " << start << ' ' << end << std::endl;
		rslt = s.substr(start, end);
		return true;
	}
	else
		return false;
}

std::string Solution::longestPalindrome_dp(std::string s)
{
    if(s.size() < 2) return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while(i < s.size()) {
        int r_ptr = i; 
        int l_ptr = i;
        //find the middle of a palindrome
        while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
        i = r_ptr+1;
        //expand from the middle out
        while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
            r_ptr++;
            l_ptr--;
        }
        int new_len = r_ptr - l_ptr + 1;
        if(new_len > max_len) {
            start_idx = l_ptr;
            max_len = new_len;
        }
    }
    return s.substr(start_idx, max_len);
}


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int a=nums1.size() + nums2.size();
	int i;
	if (a % 2 == 0)
	    i = a / 2 - 1;
	else
	    i = a / 2;

	while (i > 0)
	{
		if(nums1.size()!=0 && nums2.size()!=0)
		{
			if (nums1.back() > nums2.back())
				nums1.pop_back();
			else
				nums2.pop_back();
		}
	    else if (nums1.size()!=0)
	    	nums1.pop_back();
	    else
	    	nums2.pop_back();
		i--;
	}

	if (a % 2 == 0)
	{
		if(nums1.size()!=0 && nums2.size()!=0)
		{
			if (nums1.back() > nums2.back())
				return nums1.back();
			else
				return nums2.back();
		}
	    else if (nums1.size()!=0)
	    {	
	    	int temp = nums1.back();
	        nums1.pop_back();
	        return (temp + nums1.back()) / 2.0;
	    }
	    else
	    {
	    	int temp = nums1.back();
	        nums1.pop_back();
	        return (temp + nums1.back()) / 2.0;
	    }
	}
	else
	{
		if(nums1.size()!=0 && nums2.size()!=0)
		{
			if (nums1.back() > nums2.back())
				return nums1.back();
			else
				return nums2.back();
		}
	    else if (nums1.size()!=0)
	    	return nums1.back();
	    else
	    	return nums2.back();
	}
}

std::vector<int> standUpCallM(int n, int m)
{
	std::vector<int> origin;
	origin.resize(n);
	std::vector<int> rslt;

	int target = n;
	while (rslt.size() < target)
	{
		int standout = (n > m) ? m : m % n;
		int temp=0;
		for(int i=0;i<target;++i)
		{
			if(origin[i] != 1)
				temp++;
		    if(temp == standout)
		    {
		    	origin[i] = 1;
		    	rslt.push_back(i+1);
		    	n--;
		    }
		}
	}

	return rslt;
}