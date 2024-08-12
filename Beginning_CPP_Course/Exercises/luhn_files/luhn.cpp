#include "luhn.h"

namespace luhn 
{
    bool valid(string luhn)
    {
        string concat {""};
        for(int i {static_cast<int>(luhn.length())-1}; i>=0; i--)
        {
            if((!isdigit(luhn.at(i)))&(!isblank(luhn.at(i))))
            {
                return false;
            }
            if(isdigit(luhn.at(i)))
            {
                concat.push_back(luhn.at(i));
            }
        }
        if(concat.length() <=1)
        {
            return false;
        }
        
        int total {0};
        for(size_t i {0}; i < concat.length(); i++)
        {
            if(i % 2 != 0)
            {
                int dbl {(concat.at(i)-'0') * 2};
                if(dbl > 9)
                {
                    dbl = dbl - 9;
                }
                total = total + dbl;
            }
            else
            {
                total = total + (concat.at(i)-'0');
            }
        }
        
        if (total % 10 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}  // namespace luhn

int main()
{
    //Testing correctly formatted number
    bool test1 {luhn::valid("8273 1232 7352 0569")};
    std::cout << test1 << std::endl;

    // //Testing alphabetical junk
    // bool test2 {luhn::valid("055b 444 285")};
    // std::cout << test2 << std::endl;

    // //Testing spacer junk
    // bool test3 {luhn::valid("055-444-285")};
    // std::cout << test3 << std::endl;

    // //Testing too small
    // //Testing spacer junk
    // bool test4 {luhn::valid("0%j")};
    // std::cout << test4 << std::endl;

    bool test5 {luhn::valid("4539 3195 0343 6467")};
    std::cout << test5 << std::endl;

    bool test6 {luhn::valid("059")};
    std::cout << test6 << std::endl;
    
    return 0;
}