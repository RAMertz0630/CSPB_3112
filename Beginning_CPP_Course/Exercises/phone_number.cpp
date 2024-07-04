#include "phone_number.h"
#include <iostream>

namespace phone_number 
{
    string phone_number(string num)
    {
        string clean_number;
        for(char c: num)
            {
                if(isdigit(c))
                {
                    clean_number = clean_number + c;
                }
            }
        if(clean_number[0] == '1')
        {
            clean_number = clean_number.erase(1,0);
        }
        
        return clean_number;
    }
}  // namespace phone_number

int main()
{
    string test1 = phone_number::phone_number("(223) 456-7890");
    cout << "Result of test1 is: " << test1 << endl;
    return 1;
}
