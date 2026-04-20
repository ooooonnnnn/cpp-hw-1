///Omri Tafla
///Instructions: run from the console with as many text arguments as you like to analyze them

#include <iostream>

using namespace std;

int nums_to_analyze[] = {-11, 525, 123};

bool is_palindrome(char* number);
bool is_palindrome(int number);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "No arguments given.\n";
        return 1;
    }
    
    cout << "Text analysis:\n\n";
    
    for (int i = 1; i < argc; i++)
    {
        cout << argv[i] << ": " << (is_palindrome(argv[i]) ? "palindrome" : "not palindrome") << "\n";
    }
    
    cout << "\nAdditional integer analysis: \n\n";
    
    for (int number : nums_to_analyze)
    {
        cout << number << ": " << (is_palindrome(number) ? "palindrome" : "not palindrome") << "\n";
    }
    
    return 0;
}

bool is_palindrome(char* number)
{
    size_t length = strlen(number);
    for (size_t i = 0; i < length / 2; i++)
    {
        if (number[i] != number[length - i - 1]) return false;
    }
    return true;
}

///Assumed number up to 3 digits
bool is_palindrome(int number)
{
    if (number < 0) return false;
    
    const int max_digits = 3;
    
    for (int i = 0; i < max_digits/2; i++)
    {
        int ith_digit = (number % (int)pow(10, i+1)) / (int)pow(10, i);
        int i_from_last_digit = (number % (int) pow(10, max_digits - i)) / (int)pow(10, max_digits - 1 - i);
        
        if (ith_digit != i_from_last_digit)
        {
            return false;
        }
    }
    
    return true;
}