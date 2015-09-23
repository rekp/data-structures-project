#include <iostream>
#include <time.h> 

#ifndef _myTime
#define _myTime

class myTime
{
	public:
		void markStart();
		void markEnd();
		void markTotal();
		clock_t start_t, end_t, total_t;
};
#endif
