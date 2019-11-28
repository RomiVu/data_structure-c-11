#include <vector>
#include <iostream>
#include "tools.h"
#include "chapter1.h"

using namespace std;


void deleteDuplicates(vector<int> &v) {
    int mark = 0, duplicate=0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[mark]){
             duplicate++;
        } else {
        	v[++mark] = v[i];
        }
    }

    v.resize(v.size()-duplicate);
}


void deleteDuplicatesUnsorted(vector<int> &v) {
    int mark = 0, duplicate=0;
    for (int i = 1; i < v.size(); ++i) {
    	bool isDuplicate = false;
    	for (int j=0; j<=mark; ++j){
    		if (v[j] == v[i]){
                isDuplicate = true;
    			break;
    		}
    	}

        if (isDuplicate){
             duplicate++;
        } else {
        	v[++mark] = v[i];
        }
    }

    v.resize(v.size()-duplicate);
}


void deleteSpecific(vector<int> &v, int target){
	int duplicate=0;
    for (int i=0; i< v.size(); ++i){
        v[i- duplicate] = v[i];

    	if (v[i] == target){
    		duplicate++;
    	}
    }
    v.resize(v.size()-duplicate);
}


void deleteRangeFmTo(vector<int> &v, int low, int high){
    if (low > high) throw "fuck you motherfucker";

	int duplicate=0;
    for (int i=0; i< v.size(); ++i){
        v[i- duplicate] = v[i];

    	if (low <= v[i] && v[i]<= high){
    		duplicate++;
    	}
    }
    v.resize(v.size()-duplicate);

}


vector<int> mergeTwoSorted(vector<int> &v1, vector<int> &v2){
	// ascend
	vector<int> rslt;
	int p1=0, p2=0;
	while(p1 < v1.size() || p2 < v2.size()){
		if (p1 < v1.size() && p2 < v2.size()) {
			rslt.push_back((v1[p1] < v2[p2]) ? v1[p1++] : v2[p2++]);
		} else if (p1 < v1.size()) {
			rslt.push_back(v1[p1++]);
		} else {
			rslt.push_back(v2[p2++]);
		}
	}

	return rslt;
}

vector<int> mergeKSorted(vector<vector<int>> &v){
	// suppose all vector are ascend sorted
	vector<int> temp;

	for (int i=0; i < v.size(); i++){
		temp = mergeTwoSorted(v[i], temp);
	}

	return temp;
}


void reverseOrder(vector<int> &v, int front, int end){
	for (int i=front; i < (front+end+1)/2; ++i){
		swap(v[i], v[front+end-i]);
	}
}

void reverseTwoVector(vector<int> &v, int n, int m){
	reverseOrder(v, 0, m+n-1);
	reverseOrder(v, 0, m-1);
	reverseOrder(v, m, m+n-1);
}


int findAndInsert(vector<int> &v, int target){
	// v is ascended
	int start=0, end=v.size()-1;

	while (start <= end) {
    	int mid = (end + start) / 2;
		if (v[mid] < target){
			start =mid +1;
		} else if (v[mid] > target) {
            end = mid -1;
		} else {
            return mid;
		}
	}

	return -1;
}


double getMedianOfArray(vector<int> &v1, vector<int> &v2){
	int n =v1.size();
	int i = n / 2;
	int j = n - i;

	int lf = max(v1[i-1], v2[j-1]);
	int rg = min(v1[i], v2[j]);

	while(lf > rg){
		if(v1[i-1] > v2[j-1]){
            i--;
		} else {
		    i++;
		}

		j = n - i;

		lf = max(v1[i-1], v2[j-1]);
	    rg = min(v1[i], v2[j]);
	}
	return (lf + rg) / 2.0;
}


double getMedianOfArrayUnsorted(vector<int> &v, int start, int end){
	if (end % 2 == 0){
		return findKthLarge(v, end/2+1, start, end);
	} else {
		return findKthLarge(v, (end+1)/2 + 1, start, end);
	}
}


int findKthLarge(vector<int> &v, int k, int start, int end){
	int target = v[start];
	int i=start, j=end+1;
	
	while(true) {
		while(v[++i] < target){
			if (i == end) break;
		}

	    while(v[--j] > target){
			if (j == start) break;
	    }

		if (i >= j) break; 
		swap(v[i], v[j]);
	}

	swap(v[start], v[j]);

	// cout << "i: " << i << ", j: " << j  << " ;k: " << k << endl;
	if (k == (j+1)) {
		return v[j];
	} else if (j == start) {
		findKthLarge(v, k, start+1, end);
	} else if (k < (j+1)) {
		findKthLarge(v, k, start, j-1);
	} else if (k > (j+1)) {
		findKthLarge(v, k, j+1, end);
	}
}


void quickSort(vector<int> &v, int start, int end){
	if (start >= end) return;
	int target = (v[start] + v[end]) / 2; 
	int i = start - 1, j=end + 1;
	
	while(true){
		while(v[++i] < target){
			if (i == end)
				break;
		}

	    while(v[--j] > target){
			if (j == start)
				break;
	    }

		if (i >= j) break; 
		swap(v[i], v[j]);
	}
    
    quickSort(v, start, j);
    quickSort(v, j+1, end);

}