#include <iostream>
#include <stdio.h> 
#include <windows.h>
#include "myTime.h"

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
