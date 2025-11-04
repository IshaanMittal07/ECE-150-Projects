#include <iostream>
#include <cassert>

int main(); 


// helper function for geomteric method
double power(double base, int exp)
{
    double val = 1.0;

    for (int i = 0; i < exp; ++i)
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

        else
        {
            dynamicArray[i] = a;
        }
    }

    return dynamicArray;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)
{
    assert((cap0 + cap1) >= 1);
    double *dynamicArray = new double[cap0 + cap1 - 1](); // initalize all elements to 0

    for (std::size_t i = 0; i < cap0; ++i)
    {
        for (std::size_t j = 0; j < cap1; ++j)
        {
            dynamicArray[i + j] += array0[i] * array1[j];
        }
    }

    return dynamicArray;
}

void shift_duplicates(int array[], std::size_t capacity)
{
    int unique = 0; 
    int dup = capacity;  
    
    for (std::size_t i = 0; i < dup; ++i) {
        bool repeat = false; 

        for (std::size_t j = 0; j < unique; ++j) {
            if (array[i] == array[j]) {
                repeat = true; 
                break; 
            }
        }

        if (repeat == false) {
            if (unique != i) {
                array[unique]= array[i]; 
            }
            unique++; 
        }

        else {
            for (std::size_t k = i + 1; k < dup; ++k) {
                array[k-1] = array[k]; 
            }
            dup--; 
            i--; 
        }
    }

    for (std::size_t i = 0; i < capacity; ++i) {
        std::cout << array[i] << std::endl; 
    }
    
}

void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0)
{
    if (is_array == true)
    {
        for (std::size_t i = 0; i < capacity; ++i)
        {
            ptr[i] = 0;
        }

        delete[] ptr; // deallocating the memeory of the array
        ptr = nullptr;
    }

    else
    {
        *ptr = 0;   // sets indivudal value to zero
        delete ptr; // deallocate single instance
        ptr = nullptr;
    }
}

int main() {
    int array[20] = {8862, 8862, 5493, 7739, 2059, 4364, 6696, 973, 3297, 5514, 7823, 2183, 4489, 6734, 1095, 3386, 5671, 7992, 2268, 4506}; 
    shift_duplicates(array, 20); 
}