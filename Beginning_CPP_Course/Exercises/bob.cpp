#include "bob.h"

namespace bob 
{
    string format(string conversation)
    {
        string cleanup;
        for(char c: conversation)
        {
            if(isalnum(c))
            {
                cleanup.push_back(c);
            }
            else if(ispunct(c))
            {
                cleanup.push_back(c);
            }
        }
        return cleanup;
    }
    
    bool is_silence(string conversation)
    {
        if(conversation.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_question(string conversation)
    {
        if(conversation.at(conversation.length() -1) == '?')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_yelling(string conversation)
    {
        string all_caps;
        int letters {0};
        for(char c: conversation)
        {
            if(isalpha(c))
            {
                all_caps.push_back(toupper(c));
                letters++;
            }
            else
            {
                all_caps.push_back(c);
            }
        }

        if((conversation == all_caps) & (letters > 0))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    
    string hey(string conversation)
    {
        string clean_phrase = format(conversation);
        
        if(is_silence(clean_phrase))
        {
            return "Fine. Be that way!";
        }
        else if(is_question(clean_phrase) & !is_yelling(clean_phrase))
        {
            return "Sure.";
        }
        else if(!is_question(clean_phrase) & is_yelling(clean_phrase))
        {
            return "Whoa, chill out!";
        }
        else if(is_question(clean_phrase) & is_yelling(clean_phrase))
        {
            return "Calm down, I know what I'm doing!";
        }
        else
        {
            return "Whatever.";
        }
        
    }

}  // namespace bob

int main()
{
    //These are all fine.
    cout << bob::hey("Feeling a a little hormonal today?") << endl;
    cout << bob::hey("WHO TOLD YOU YOU COULD EAT MY COOKIES?") << endl;
    cout << bob::hey("Was I talking to you? No.") << endl;
    cout << bob::hey("NO, ME SMOKE BEES!") << endl;

    //Why are these failing?
    cout << bob::hey("4?") << endl;
    cout << bob::hey("") << endl;
    
    return 0;
}