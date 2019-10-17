#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <utility>

template <typename Object>
class matrix
{
private:
	std::vector<std::vector<Object>> array;
public:
	matrix(int rows, int columns)
	{
		array.resize(rows);
		for (auto & row : array)
			row.resize(columns);
	}

	matrix(std::vector<std::vector<Object>> v) : array {v}
	{
	}
	matrix(std::vector<std::vector<Object>> && v) : array {std::move(v)}
	{
	}

	const std::vector<Object> & operator[]( int row ) const
	{
		return array[row];
	}

    std::vector<Object> & operator[]( int row )
    {
    	return array[row];
    }

    int numrows( ) const
    {
    	return array.size();
    }

    int numcols( ) const
    {
    	return numrows() ? array[0].size() : 0;
    }
};

#endif

