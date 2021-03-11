/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Jose de la Cruz
 * Date        : 9/23/2020
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    for (size_t i = 0; i < s.length(); i++)
    {
        if(!islower(s[i])){
            cout << "Error: String must contain only lowercase letters.";
            return false;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    int setter = 0;
    int storage = 0;
    int result = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        setter = 1 << (s[i] - 'a');
        result = storage & setter;
        
        if(result == setter){
            cout << "Duplicate letters found.";
            return false;
        }
        else
        {
            storage = (storage | setter);
            result = 0;
        }
    }
    cout << "All letters are unique.";
    return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    
    if (argc != 2)
    {
        cout << "Usage: ./unique <string>";
        return 1;
    }
    else
    {
        string s = argv[1];
        if(is_all_lowercase(s)){
            all_unique_letters(s);
        }
    }
    

    return 0;
}
