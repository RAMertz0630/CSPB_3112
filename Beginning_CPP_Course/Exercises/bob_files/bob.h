#if !defined(BOB_H)
#define BOB_H

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

namespace bob 
{
    bool is_silence(string conversation);
    bool is_question(string conversation);
    bool is_yelling(string conversation);
    string hey(string conversation);

}  // namespace bob

#endif // BOB_H