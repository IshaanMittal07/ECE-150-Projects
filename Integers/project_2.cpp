#include <iostream>
#include <cassert>

int main();

void pattern(unsigned int n)
{
    if (n == 0)
    {
        std::cout << "*" << std::endl;
    }

    // for loop for drawing  2n + 1
    // for loop for spaces

    else
    {
        for (unsigned int row = 1; row <= ((2 * n + 1) / 2 + 1); row++)
        {
            if (row == 1)
            {
                for (unsigned int i = 0; i < (2 * n + 1); i++)
                {
                    std::cout << "*";
                }
            }

            else
            {
                for (unsigned int space = 1; space < row; space++)
                {
                    std::cout << " ";
                }

                for (unsigned int col = 0; col < ((2 * n + 1) - ((row - 1) * 2)); col++)
                {
                    std::cout << "*";
                }
            }

            std::cout << std::endl;
        }

        // TRY TO INVERT THIS
        for (unsigned int row = ((2 * n + 1) / 2); row >= 1; row--)
        {
            if (row == 1)
            {
                for (unsigned int i = 0; i < (2 * n + 1); i++)
                {
                    std::cout << "*";
                }
            }

            else
            {
                for (unsigned int space = 1; space < row; space++)
                {
                    std::cout << " ";
                }

                for (unsigned int col = 0; col < ((2 * n + 1) - ((row - 1) * 2)); col++)
                {
                    std::cout << "*";
                }
            }

            std::cout << std::endl;
        }
    }
}

unsigned int log10(unsigned int n)
{
    assert(n != 0);
    unsigned int m = 0;
    if (n >= 1 && n < 10)
    {

        return 0;
    }

    else
    {

        while (n >= 10)
        {
            n /= 10;
            m++;
        }

        return m;
    }
}

unsigned int count(unsigned int n, unsigned int bit)
{
    assert(bit == 0 || bit == 1);
    unsigned int counter = 0;
    for (int i = 0; i < 32; ++i) {
        if (((n >> i) & 0b1U) == bit) { //keep on shifting all the bits and keep on checking if they are equal to one specificed
            counter++; 
        } 
    }

    return counter; 
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1)
{
    assert((0 <= b0 && b0 <= 3) && (0 <= b1 && b1 <= 3)); 

    unsigned int temp;  // b0
    unsigned int temp2; // b1

    if (b0 == b1)
    {
        return n;
    }

    else
    {
        temp = (n >> 8 * b0) & (0x0FFU);
        temp2 = (n >> 8 * b1) & (0x0FFU); // putting them into the very end

        temp <<= 8 * b1;
        temp2 <<= 8 * b0;

        return ((temp | temp2) | ((~((0x0FFU << 8 * b0) | (0x0FFU << 8 * b1))) & n));
    }
}

int main()
{
    pattern(5);
    std::cout << log10(4294967295) << std::endl; 
    std::cout << swap_bytes(1864063492, 3, 3) << std::endl;
    std::cout << count(4294705151, 0) << std::endl; 
    return 0;
}
