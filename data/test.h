#ifndef TEST_H
#define TEST_H

/**
* A class for simulating an integer memory cell.
*/
class IntCell
{
private:
    int storedValue;
public:
	explicit IntCell(int initialValue = 0);
	int read() const;
	void write(int x);
};

#endif