#include "rotational_cipher.h"

namespace rotational_cipher 
{
    string rotate(string message, int key)
    {
        string ciphertext;
        string alpha {"abcdefghijklmnopqrstuvwxyz"};

        for(char c: message)
        {
            if(isalpha(c))
            {
                if(isupper(c))
                {
                    ciphertext.push_back(toupper(alpha.at((alpha.find(tolower(c))+key) % 26)));
                }
                
                else
                {
                    ciphertext.push_back(alpha.at((alpha.find(tolower(c))+key) % 26));  
                }
            }
            else
            {
                ciphertext.push_back(c);
            }  
        }
        
        return ciphertext;
    }
}  // namespace rotational_cipher

int main()
{
    string encryption {rotational_cipher::rotate("ZZZ", 1)};
    cout << encryption << endl;

    return 0;
}
