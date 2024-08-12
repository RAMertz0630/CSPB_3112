#if !defined(LUHN_H)
#define LUHN_H

#include <string>
#include <cctype>
#include <iostream>

using std::string;

namespace luhn 
{
    bool valid(string luhn);
}  // namespace luhn

#endif // LUHN_H