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

    while (true) {
        

        if (str1[i] == '\0' && str2[i] == '\0') {
            return 0; 
        }

        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i]) {
                return -1; 
            }

            else {
                return 1; 
            }
        }

        ++i; 

        //When the word is like cat and catostrophe the str[3] position is the null character which is always going to smaller than the character it is being compared to, which is why the longer word (catostrophe) comes after the short word (cat)

    }
    
}

void assign(char *str1, char const *str2) {
    int i = 0; 
    while (str2[i] != '\0') {

        str1[i] = str2[i]; 
        ++i;  
    }

    str1[i] = '\0';  //null characetr 

}

unsigned int distance( char const *str1, char const *str2) {
    if (str1 == "") {
        return length(str2); 
    } 

    else if(str1[0] == str2[0]) {
        distance(str1 + 1, str2 + 1); 
    }

    else if (str1[0] != str2[0]) {

    }
    else {
        return length(str1); 
    }


    int i = 0; 

    

}


int main()
{

    //Notes: 
    //Lets say we had char *str1 = brake and char *str2 = str1 +1 
    //Then eveyrtime u print str2 u would get an output of rake (becuase the pointer will point to the second character 'r')
    char myString[] = "test"; 
    char myString2[] = "test2"; 

    assign(myString, myString2); 
    


    std::cout << myString << std::endl;
}