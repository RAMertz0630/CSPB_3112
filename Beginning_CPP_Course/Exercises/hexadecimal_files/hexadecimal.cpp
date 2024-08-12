#include "hexadecimal.h"

namespace hexadecimal 
{
    int convert(string hex)
    {
        string geq9 {"abcdef"};
        vector<int> dec9 {10, 11, 12, 13, 14, 15, 16};
        
        int decimal {0};
        int exp {0};
        for(int i {static_cast<int>(hex.length()) - 1}; i >=0; i--)
        {
            if((isalpha(hex.at(i)))&(geq9.find(hex.at(i))==std::string::npos))
            {
                return 0;
            }
            else if((isalpha(hex.at(i)))&(geq9.find(hex.at(i))!=std::string::npos))
            {
                decimal += dec9.at(geq9.find(hex.at(i))) * pow(16, exp);
            }
            else
            {
                decimal += (hex.at(i)-'0') * pow(16, exp);
            }
            
            exp++;
        }

        return decimal;
    }

}  // namespace hexadecimal

int main()
{
    int test1 {hexadecimal::convert("c")};
    std::cout << test1 << std::endl;

    int test2 {hexadecimal::convert("poop")};
    std::cout << test2 << std::endl;
    
    return 0;
}