#include <iostream>
#include <string>
#include <vector>


using namespace std;


// Function to perform leftmost derivation
void leftmost_derivation(string derivation)
{
    size_t pos;


    cout << derivation << " => ";
    pos = derivation.find('S');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "E");
    }
    cout << derivation << endl;


    cout << derivation << " => ";
    pos = derivation.find('E');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "E + T");
    }
    cout << derivation << endl;


    cout << derivation << " => ";
    pos = derivation.find('E');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "T");
    }
    cout << derivation << endl;
}


// Function to perform rightmost derivation
void rightmost_derivation(string derivation)
{
    size_t pos;


    cout << derivation << " => ";
    pos = derivation.rfind('S');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "E");
    }
    cout << derivation << endl;


    cout << derivation << " => ";
    pos = derivation.rfind('E');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "E + T");
    }
    cout << derivation << endl;


    cout << derivation << " => ";
    pos = derivation.rfind('T');
    if (pos != string::npos)
    {
        derivation.replace(pos, 1, "T * F");
    }
    cout << derivation << endl;
}


int main()
{
    cout << "Done by Aashutosh Pudasaini" << endl;
    string expression = "S"; // Start symbol


    // Leftmost derivation
    cout << "Leftmost Derivation: \n";
    leftmost_derivation(expression);


    // Rightmost derivation
    cout << "\nRightmost Derivation: \n";
    rightmost_derivation(expression);


    return 0;
}
