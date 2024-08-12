#include "trinary.h"

namespace trinary 
{

int to_decimal(string trinary_num)
    {
        string permitted_digits {"012"};
        int decimal_num {0};
        const int base {3};
        int exp {static_cast<int>(trinary_num.length())-1};

        for(size_t i {0}; i < trinary_num.length(); i++)
        {
            if(permitted_digits.find(trinary_num.at(i)) == string::npos)
            {
                decimal_num = 0;
                break;
            }
            else
            {
                decimal_num += stoi(trinary_num.substr(i, 1).c_str()) * pow(base, exp);
            }
            exp--;
        }
        return decimal_num;
    }

}  // namespace trinary

int main()
{
    cout << trinary::to_decimal("102012") << endl;
    cout << trinary::to_decimal("pickle") << endl;
    
    return 0;
}