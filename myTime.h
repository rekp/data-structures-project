// File: myTime.h
// Author: Patrick Rek
// Date : Spring 2014 
// Last Updated by: Patrick Rek 24/09/15
// Description: Class to track how long AVL tree creation and searches take.

#include <iostream>
#include <time.h>
#include <stdio.h> 
#include <windows.h>

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

void myTime::markStart()
{
    start_t = clock();
}
void myTime::markEnd()
{
    end_t = clock();
}
void myTime::markTotal()
{
	//SYSTEMTIME ww;
	//GetLocalTime(&ww);
	//return ww.wMilliseconds;*/
    total_t = (end_t - start_t);
	printf ("took %d clicks (%f seconds)\n",total_t,((float)total_t)/CLOCKS_PER_SEC);
}