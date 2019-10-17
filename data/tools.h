#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
#include <chrono> // for std::chrono functions
#include <iostream>

void CloseWindow();

template <typename T>
void printVector(const T& x)
{
	int dot = 0;
    for (int i=0; i<x.size(); ++i)
    	if (i < 6 || i > x.size()-6)
            std::cout << x[i] << ' ';
        else if (dot < 3)
        	{
        		std::cout << ". ";
        		dot++;
        	}
    std::cout << '\n';
}

int getRandomNumber(int min, int max);


template <typename Container>
void removeEveryOtherItem( Container & lst )
{
	auto itr = lst.begin( );

	while( itr != lst.end( ) )
	{
		itr = lst.erase( itr );
		if( itr != lst.end( ) )
		   ++itr;
 	}
 }

 
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
 
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
 
	void reset()
	{
		m_beg = clock_t::now();
	}
 
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}

	double interval()
	{
		double temp = std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
		// m_beg = clock_t::now();
		reset();
		return temp;
	}
};


template <typename Comparable>
void bubbleSort(std::vector<Comparable> &v)
{
    int n = v.size();
    for(int i=0;i<n-1;++i)
    	for(int j=0;j<n-i-1;++j)
    		if(v[j] > v[j+1])
    			std::swap(v[j], v[j+1]);
}

template <typename Comparable>
void insertSort(std::vector<Comparable> &v)
{
	int n = v.size();
}

template <typename Comparable>
void insertBiSort(std::vector<Comparable> &v)
{
	int n = v.size();
}

template <typename Comparable>
void insertShellSort(std::vector<Comparable> &v)
{
	int n = v.size();
}

template <typename Comparable>
int partition(std::vector<Comparable> &v, int low, int high)
{
	Comparable pivot = v[low];

	while(low < high)
	{
		while(low<high && v[high]>=pivot) --high;
		v[low] = v[high];
		while(low<high && v[low]<=pivot) ++low;
		v[high] = v[low];
	}

	v[low] = pivot;
	return low;
}

template <typename Comparable>
void quickSort(std::vector<Comparable> &v, int low, int high)
{
	if (low < high){
		int pivot = partition(v, low, high);
		quickSort(v,low, pivot-1);
		quickSort(v,pivot+1, high);
	}
}



template <typename Comparable>
void selectSort(std::vector<Comparable> &v)
{
	int n = v.size();
    for(int i=0;i<n;++i)
    {
	int min=i;
	for(int j=i+1;j<n;++j)
		if(v[j] < v[min]) min = j;
	if(min != i)
		std::swap(v[i], v[min]);
	}
}


template <typename Comparable>
void AdjustDown(std::vector<Comparable> &v, int k, int length)
{
	Comparable temp = v[k];
	for (int i=(2*k + 1); i<length;i=(2*i+1))
	{
		//std::cout << "AdjustDown BEFORE: i = " << i << " ; and k = " << k << '\n';
		if ((i+1) < length && v[i] < v[i+1])
			i++;

		if (temp > v[i])
			break;
		else
		{
			v[k] = v[i];
			k = i;
		}
		//std::cout << "AdjustDown AFTER: i = " << i << " ; and k = " << k << '\n';
	}
	v[k] = temp;
}


template <typename Comparable>
void buildMaxHeap(std::vector<Comparable> &v, int n)
{
	for(int i=(n-2)/2;i>=0;--i)
	{	
		//std::cout << "i = " << i  << '\n';
		AdjustDown(v, i, n);
	}
	//std::cout << '\n';
}

template <typename Comparable>
void heapSort(std::vector<Comparable> &v)
{
	buildMaxHeap(v, v.size());
	for(int i=v.size()-1;i>0;--i)
	{
		std::swap(v[0], v[i]);
		buildMaxHeap(v, i);
	}

}

template <typename Comparable>
void merge(std::vector<Comparable> &v, int start, int mid, int end)
{

}

template <typename Comparable>
void mergeSort(std::vector<Comparable> &v)
{

}

#endif