#include <iostream>

int main();

std::size_t length(char const *a)
{ // calculates the number of characters in the string (the length) by counting the number of characters before the first null character '\0' and returning that number.
    // pointer to the first character of a sequence (a C-string)
    std::size_t i = 0;
    std::size_t counter = 0;
    while (true)
    {
        if (a[i] == '\0')
        {
            break;
        }

        else
        {
            ++counter;
        }
        ++i;
    }

    return counter;
}

int compare(char const *str1, char const *str2)
{
    int i = 0;

    while (true)
    {

        if (str1[i] == '\0' && str2[i] == '\0')
        {
            return 0;
        }

        if (str1[i] != str2[i])
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }

            else
            {
                return 1;
            }
        }

        ++i;

        // When the word is like cat and catostrophe the str[3] position is the null character which is always going to smaller than the character it is being compared to, which is why the longer word (catostrophe) comes after the short word (cat)
    }
}

void assign(char *str1, char const *str2)  //assign str2 to str1
{
    int i = 0;
    while (str2[i] != '\0')
    {

        str1[i] = str2[i];
        ++i;
    }

    str1[i] = '\0'; // null characetr
}

unsigned int distance(char const *str1, char const *str2)
{
    if (str1[0] == '\0')
    {
        return length(str2);
    }

    if (str2[0] == '\0')
    {
        return length(str1);
    }

    if (str1[0] == str2[0])
    {
        return distance(str1 + 1, str2 + 1);
    }

    else
    {
        return (1 + std::min(
                        distance(str1 + 1, str2 + 1),
                        std::min(distance(str1 + 1, str2), distance(str1, str2 + 1)))); // do this since you can only compare two args in std::min()
    }
}

std::size_t is_sorted(char *array[], std::size_t capacity)
{
    for (std::size_t k{0}; k < capacity - 1; ++k)
    {
        if (compare(array[k], array[k + 1]) > 0) // since they are pointers I have to use the compare method, otherwise I wouldve been comparing memory addresses
        {
            return k + 1;
        }
    }
    return capacity;
}

void insert(char *array[], std::size_t capacity)
{    
    std::size_t len = length(array[capacity - 1]); 
    char *value = new char[len + 1]; 
    assign(value, array[capacity - 1]); 

    //pointer to be deleted later to avoid memory leak
    char *copy = array[capacity - 1];


    std::size_t k{};
    for (k = capacity - 1; (k > 0) && (compare(array[k-1], value) > 0); --k)
    {
        array[k] = array[k - 1];
    }
    
    array[k] = value;

    delete[] copy; 
    copy = nullptr; 
}


void insertion_sort(char *array[], std::size_t capacity) {
    for (std::size_t k{2}; k <= capacity; ++k) {
        insert(array, k); 
    }
}


std::size_t remove_duplicates(char *array[], std::size_t capacity) {
    std::size_t unique{0}; 

    if (capacity == 0) { //just in case for marmoset secreat tests

        return 0; 
    }

    for (std::size_t k{1}; k < capacity; ++k) {
        if (compare(array[k], array[unique]) != 0) { //check the ones beside each other
            ++unique;
            array[unique] = array[k]; //keep on moving to the left
        }

    }

    return (unique + 1); //its unique + 1 bc of the diff bt index and element


}

std::size_t find(char *array[], std::size_t capacity, char const *str) {
    for (std::size_t k{0}; k < capacity; ++k) {
        if (compare(array[k], str) == 0) {
            return k; 
        }
    }

    std::size_t index{0}; 
    unsigned int shortest = distance(array[0], str); 

    for (std::size_t k{1}; k < capacity; ++k) { //finding the shortest distance
        unsigned int value = distance(array[k], str);
        if (value < shortest) {
            shortest = value;
            index = k;
        }
    }
    return index; 

}
int main()
{

    // Notes:
    // Lets say we had char *str1 = brake and char *str2 = str1 +1
    // Then eveyrtime u print str2 u would get an output of rake (becuase the pointer will point to the second character 'r')
    char myString[] = "cpple";
    char myString2[] = "aocomelon";

    char *Array[] = {myString, myString2};

    std::cout << is_sorted(Array, 2) << std::endl;
}