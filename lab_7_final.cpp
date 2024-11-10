#include <iostream>
#include <string>


using namespace std;


// Function to simulate Turing Machine for L = { a^n b^n | n ≥ 1 }
bool turingMachine(string input)
{
    int i = 0, j = input.size() - 1;


    // Step through the string from both ends to mark matching a's and b's
    while (i < j)
    {
        if (input[i] == 'a' && input[j] == 'b')
        {
            input[i] = 'X'; // Mark 'a' as visited
            input[j] = 'Y'; // Mark 'b' as visited
            i++;            // Move i forward to find next 'a'
            j--;            // Move j backward to find next 'b'
        }
        else if (input[i] == 'X')
        {
            i++; // Skip already marked 'a's
        }
        else if (input[j] == 'Y')
        {
            j--; // Skip already marked 'b's
        }
        else
        {
            return false; // Mismatch in structure
        }
    }


    // Check if all 'a's are matched with 'b's
    for (char c : input)
    {
        if (c == 'a' || c == 'b')
            return false;
    }
    return true; // All matches were found
}


int main()
{
    string input;
    cout << "Done by Aashutosh Pudasaini" << endl;
    cout << "Enter a string (only a's followed by b's): ";
    cin >> input;


    // Check if the input is in the language L
    if (turingMachine(input))
    {
        cout << "The string is accepted by the Turing Machine.\n";
    }
    else
    {
        cout << "The string is rejected by the Turing Machine.\n";
    }


    return 0;
}


