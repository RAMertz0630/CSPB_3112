#include "prime_factors.h"

namespace prime_factors 
{
    vector<int> of(int num)
    {
        vector<int> primes {};
        int div {num};

        for(int i {2}; i <=div; i++)
        {
            int rem {div % i};

            while(rem==0)
            {
                div = div / i;
                rem = div % i;
                primes.push_back(i);
            }
        }

        return primes;
    }
}  // namespace prime_factors

int main()
{
    vector<int> test1 {prime_factors::of(60)};
    
    for(size_t i {0}; i < test1.size(); i++)
    {
        std::cout << test1.at(i) << std::endl;
    }
    
    return 0;
}
