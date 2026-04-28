///Omri Tafla
///Instructions: run from the console with as many text arguments as you like to analyze them

#include <iostream>
#include <map>

using namespace std;

map<char, int> numerals = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

int roman_to_int(string roman);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "No arguments given.\n";
        return 1;
    }
    
    cout << "Results :\n\n";
    
    for (int i = 1; i < argc; i++)
    {
        cout << argv[i] << ": " << roman_to_int(argv[i]) << "\n";
    }
    
    return 0;
}

int roman_to_int(string roman)
{
    size_t index = -1;
    unsigned long value = 0;
    char current_char;
    do
    {
        index++;
        current_char = roman[index];
        switch (current_char)
        {
        case 'I':
            if (roman[index + 1] == 'V' || roman[index + 1] == 'X')
            {
                value -= numerals[current_char];
                continue;
            }
        case 'X':
            if (roman[index + 1] == 'L' || roman[index + 1] == 'C')
            {
                value -= numerals[current_char];
                continue;
            }
        case 'C':
            if (roman[index + 1] == 'D' || roman[index + 1] == 'M')
            {
                value -= numerals[current_char];
                continue;
            }
        }
        value += numerals[current_char];
    } while (current_char != 0);
    
    return value > numeric_limits<int>::max() ? numeric_limits<int>::max() : (int)value;
}
