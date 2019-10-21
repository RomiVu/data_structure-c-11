#ifndef TOOL_H
#define TOOL_H
#include <vector>
#include <chrono> // for std::chrono functions
#include <iostream>

void CloseWindow();

int getRandomNumber(int min, int max);

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


#endif