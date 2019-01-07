#include <iomanip>
#include <iostream>

unsigned long long ipow(unsigned long long base, unsigned long long exp)
{
    unsigned long long result = 1;
    for (;;) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        if (!exp) {
          break;
        }
        base *= base;
    }

    return result;
}

/*
 Check if 3^n - 1 for all n mod 2 == 0 for all n as positive integers
*/

int main(int ac, char* av[])
{      
    #pragma omp parallel for
    for (unsigned long long i = 1; (ipow(3, i) - 1) % 2 == 0; ++i) {
      if (i == 0) {
        std::cout << "overflow" << std::endl;
      }
    }
	
	return 0;
}

