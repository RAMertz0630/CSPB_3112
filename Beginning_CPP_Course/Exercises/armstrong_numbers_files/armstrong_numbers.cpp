#include "armstrong_numbers.h"

namespace armstrong_numbers 
{
    bool is_armstrong_number(int num)
    {
        int armstrong_sum{0};
        int divisor{num};
        int exp = static_cast<int>(to_string(num).length());
        for(size_t i {0}; i < exp; i++)
        {
            armstrong_sum += pow(divisor % 10, exp);
            divisor = divisor / 10;
        }
        
        if(armstrong_sum == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}  // namespace armstrong_numbers

int main()
{
    //This works
    // cout << armstrong_numbers::is_armstrong_number(9) << endl;
    // cout << armstrong_numbers::is_armstrong_number(0) << endl;

    //Why is this failing?
    cout << armstrong_numbers::is_armstrong_number(153) << endl;

    return 0;
}
