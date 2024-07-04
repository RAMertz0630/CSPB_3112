#include "eliuds_eggs.h"

namespace chicken_coop 
{
    string binary_digit(int num)
    {
        string binary;
        int dividend {num};
        while(dividend > 0)
        {
            int remainder {dividend % 2};
            dividend /= 2;
            if(remainder == 1)
            {
                binary.push_back('1');
            }
            else
            {
                binary.push_back('0');
            }
        }
        
        return binary;
    }
    
    int positions_to_quantity(int digit)
    {
        string binary_str = binary_digit(digit);
        int num_eggs{0};
        if(empty(binary_str))
        {
            return num_eggs;
        }
        else
        {
            for(char c: binary_str)
            {
                if(int(c) == int('1'))
                {
                    num_eggs++;
                }
            }
            return num_eggs;
        }
    }
}  // namespace chicken_coop

int main()
{
    cout << chicken_coop::positions_to_quantity(16) << endl;
    return 0;
}
