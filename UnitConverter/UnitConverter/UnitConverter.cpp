// Omri Tafla



#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> units = {"m", "km", "cm", "feet"};
vector<double> values_in_meters = {1, 1000, 0.01f, 0.3048f};

double input_choose_unit(string prompt, string* unit_name);

void main()
{
    //Greet user
    cout << "\nWelcome to the unit converter!\n\n";
    
    // choose base unit from list
    string base_unit_name;
    double base_unit_value = input_choose_unit("What is your base unit?", &base_unit_name);
    
    // choose target unit from remaining list
    string target_unit_name;
    double target_unit_value = input_choose_unit("What is your target unit?", &target_unit_name);
    
    double trans_factor = base_unit_value / target_unit_value;
    
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
        
        cout << parsed_number << " " << base_unit_name << " = " << 
            parsed_number * trans_factor << " " << target_unit_name <<
                "\n";
        
        cout << "Enter a non number to exit\n";
    }
}

///Prompts the user to type the name of a unit from the list, then deletes that unit.
///@param unit_name The name of the chosen unit
///@return The value in meters of the chosen unit
double input_choose_unit(string prompt, string* unit_name = nullptr)
{
    double unit_value;
    while(true)
    {
        cout << prompt << " { ";
        for (auto unit : units)
        {
            cout << unit << " ";
        }
        cout << "}\n";
        
        string chosen_unit;
        cin >> chosen_unit;
        for(int i = 0; i < units.size(); i++)
        {
            if (chosen_unit == units[i])
            {
                unit_value = values_in_meters[i];
                *unit_name = units[i];
                
                units.erase(units.begin() + i);
                values_in_meters.erase(values_in_meters.begin() + i);
                return unit_value;
            }
        }
        cout << "No such unit.\n";
    }
}
