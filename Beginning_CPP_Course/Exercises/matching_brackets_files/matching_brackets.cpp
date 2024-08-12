#include "matching_brackets.h"
#include <iostream>

namespace matching_brackets 
{
    bool check(string word)
    {
        //First, pull all of the brackets into a vector
        vector<int> unicode_vals {};
        for(char c: word)
            {
                if((c == '{') | (c == '}') | 
                    (c == '(') | (c == ')')|
                    (c == '[') | (c == ']'))
                {
                    unicode_vals.push_back(int(c));
                }
            }
        
        //Quick failsafe to ensure that the number of entries is even
        int length_uni = static_cast<int>(unicode_vals.size());
        if(length_uni % 2 != 0)
        {
            return false;
        }
        
        //Separate contiguous pairs from nested brackets
        vector<int> pairs{};
        vector<int> nests{};
        for(int i = 0; i < length_uni; i++)
            {
               if(i < (length_uni - 1))
               {
                    int difference{unicode_vals.at(i+1)-unicode_vals.at(i)};
                    if((difference <= 2) & (difference > 0))
                    {
                        pairs.push_back(unicode_vals[i]);
                        pairs.push_back(unicode_vals[i+1]);
                        i++;
                    }
                    else
                        {
                            nests.push_back(unicode_vals[i]);
                        } 
                }
                else
                {
                    nests.push_back(unicode_vals[i]);
                }
            }
        
        //Quick exit if all pairs
        int length_pairs = static_cast<int>(pairs.size());
        if(length_uni == length_pairs)
        {
            return true;
        }

        //Test for successful nesting
        int length_nests = static_cast<int>(nests.size());
        for(int i = 0; i < length_nests/2; i++)
            {
                int difference{nests.at(length_nests-1-i)-nests.at(i)};
                if((difference > 2) | (difference <= 0)) 
                {
                    return false;
                }
        }
        
        return true;
    }

}  // namespace matching_brackets

int main()
{
    
    bool test1 = matching_brackets::check("[]");
    cout << "Result of test1 is " << test1 << endl;

    bool test2 = matching_brackets::check("{[)][]}");
    cout << "Result of test2 is " << test2 << endl;

    bool test3 = matching_brackets::check("([{}({}[])])");
    cout << "Result of test3 is " << test3 << endl;

    bool test4 = matching_brackets::check("}{");
    cout << "Result of test4 is " << test4 << endl;
    
    return 1;
}