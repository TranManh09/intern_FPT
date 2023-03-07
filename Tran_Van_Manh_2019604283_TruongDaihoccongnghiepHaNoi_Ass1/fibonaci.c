#include "fibonacci.h"
/**
 * find Fibonacci number at number n
 * 
 * @param n:  Fibonacci is calculate from 1	 
 *           vd: F1 = 1, F2 = 1, F3 = 2
 * @return Fibonacci number at number n
 */
 
unsigned long long int fibonacci(int n) {
    unsigned long long int f0 = 0; /* declare number 1 */
    unsigned long long int f1 = 1; /* declare number 2 */
    unsigned long long int fn = 1; /* declare number 3 */
    unsigned long long int i = 2;
 
    if (n == 1)
	{
        return n;
    } 
	else {
        for (i = 2; i < n; i++) 
		{
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;/* create Fibonacci */
        }
    }
    return fn;
}
