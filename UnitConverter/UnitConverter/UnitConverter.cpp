// Omri Tafla



#include <iostream>
#include <string>

using namespace std;

void main()
{
    const int num_units = 4;
    string units[num_units] = {"m", "km", "cm", "feet"};
    float values_in_meters[num_units] = {1, 1000, 0.01f, 0.3048f};
    
    // choose base unit from list
    bool is_valid = false;
    int base_unit_ind = -1;
    while(!is_valid)
    {
        cout << "Enter base unit from: ";
        for (auto unit : units)
        {
            cout << unit << " ";
        }
        cout << "\n";
        
        string chosen_unit;
        cin >> chosen_unit;
        for(int i = 0; i < num_units; i++)
        {
            if (chosen_unit == units[i])
            {
                base_unit_ind = i;
                is_valid = true;
            }
        }
        if (is_valid) break;
        cout << "No such unit.\n";
    }
    
    // choose target unit from sub list
    is_valid = false;
    int target_unit_ind = -1;
    while(!is_valid)
    {
        cout << "Enter target unit from: ";
        string unit;
        for (int i = 0; i < num_units; i++)
        {
            if (i == base_unit_ind) continue;
            unit = units[i];
            cout << unit << " ";
        }
        cout << "\n";
        
        string chosen_unit;
        cin >> chosen_unit;
        for(int i = 0; i < num_units; i++)
        {
            if (i == base_unit_ind) continue;
            
            if (chosen_unit == units[i])
            {
                target_unit_ind = i;
                is_valid = true;
            }
        }
        if (is_valid) break;
        cout << "No such unit.\n";
    }
    
    //enter numbers
    while (true)
    {
        cout << "Enter number: ";
        string number_string;
        cin >> number_string;

        float parsed_number;
        try
        {
            parsed_number = stof(number_string);
        }
        catch (...)
        {
            cout << "Invalid number, exiting.\n";
            return;
        }
        
        cout << parsed_number << units[base_unit_ind] << " = " << 
            parsed_number * values_in_meters[base_unit_ind] / values_in_meters[target_unit_ind] << units[target_unit_ind] <<
                "\n";
        
        cout << "Enter a non number to exit\n";
    }
}
