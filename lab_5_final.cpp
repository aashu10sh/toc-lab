#include <iostream>
#include <string>
#include <memory>
#include <cctype> // For isdigit function


using namespace std;


// Node class for expressions (E), terms (T), factors (F)
class ExprNode
{
public:
    string value;
    shared_ptr<ExprNode> left, right;


    ExprNode(const string &val) : value(val), left(nullptr), right(nullptr) {}


    // Function to print the node and its subtree
    void printTree(int level = 0)
    {
        for (int i = 0; i < level; ++i)
            cout << "    "; // Indentation for tree
        cout << value << endl;
        if (left)
            left->printTree(level + 1);
        if (right)
            right->printTree(level + 1);
    }
};


// Function to parse an expression (recursive descent parsing)
shared_ptr<ExprNode> parseExpression(const string &expr, int &index);
shared_ptr<ExprNode> parseTerm(const string &expr, int &index);
shared_ptr<ExprNode> parseFactor(const string &expr, int &index);


// Function to parse expressions (E → E + T | T)
shared_ptr<ExprNode> parseExpression(const string &expr, int &index)
{
    auto node = parseTerm(expr, index);


    while (index < expr.size() && expr[index] == '+')
    {
        char op = expr[index++];
        auto right = parseTerm(expr, index);
        auto newNode = make_shared<ExprNode>(string(1, op));
        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }
    return node;
}


// Function to parse terms (T → T * F | F)
shared_ptr<ExprNode> parseTerm(const string &expr, int &index)
{
    auto node = parseFactor(expr, index);


    while (index < expr.size() && expr[index] == '*')
    {
        char op = expr[index++];
        auto right = parseFactor(expr, index);
        auto newNode = make_shared<ExprNode>(string(1, op));
        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }
    return node;
}


// Function to parse factors (F → ( E ) | id)
shared_ptr<ExprNode> parseFactor(const string &expr, int &index)
{
    if (index < expr.size() && expr[index] == '(')
    {
        ++index;
        auto node = parseExpression(expr, index);
        if (index < expr.size() && expr[index] == ')')
            ++index;
        return node;
    }


    string value = "";
    while (index < expr.size() && isdigit(expr[index]))
    {
        value += expr[index++];
    }
    return make_shared<ExprNode>(value);
}


int main()
{
    cout << "Done by Aashutosh Pudasaini" << endl;
    string expression = "3+5*2";
    int index = 0;
    auto root = parseExpression(expression, index);


    cout << "Input Expression: " << expression << endl;
    cout << "Parse Tree:" << endl;
    root->printTree(); // Print the tree


    return 0;
}
