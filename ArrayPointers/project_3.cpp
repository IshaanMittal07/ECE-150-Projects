#include <iostream>
#include <cassert>

int main();


//helper function for geomteric method
double power(double base, int exp)
{
    double val = 1.0;

    for (double i = 0; i < exp; ++i)
    {
        val *= base;
    }

    return val; 
}

double *geometric(double a, double ratio, std::size_t cap)
{
    // returns the address of the array that stores the values ar, ar^2 .... ar^n-1
    double *dynamicArray = new double[cap];
    double val = 0; 

    for (std::size_t i = 0; i < cap; ++i)
    {
        if (i > 0)
        {
            val = a * power(ratio, i);
            dynamicArray[i] = val; 

        }
        
        else {
            dynamicArray[i] = a; 
        }
    }


    return dynamicArray;
}

int main()
{
    std::cout << *geometric(2, 2, 3); 
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)
{
    assert((cap0 + cap1) >= 1); 
    double *dynamicArray = new double[cap0 + cap1 -1](); //initalize all elements to 0

    for (int i = 0; i < cap0; ++i) {
        for (int j = 0; j < cap1; ++j) {
            dynamicArray[i + j] += array0[i] * array1[j]; 
        }
    }

    return dynamicArray; 

}

std::size_t shift_duplicates(int array[], std::size_t capacity)
{
}

void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0)
{
    
}