#include <stack>
#include <string>
#include <iostream>

using namespace std;

// ({[]})
// {()}
// [{{()}}]
// []{}(){()}
// {(])}
// {[(])}
// {[(())]}
// {([])}

bool is_str_valid(const string& str) {
    stack<char> p;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            p.push(str[i]);
        else {
            if (p.size() == 0)
                return false;
            if ((p.top() == '{' && str[i] != '}') ||
            (p.top() == '(' && str[i] != ')') ||
            (p.top() == '[' && str[i] != ']'))
                return false;
            p.pop();
        }
    }
    return p.empty();
}

bool is_str_valid_V2(const string& str) {
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '{')
            x++;
        else if (str[i] == '(')
            y++;
        else if (str[i] == '[')
            z++;
        else {
            if (i == 0)
                return false;
            if (str[i] == '}' && (str[i - 1] == '[' || str[i - 1] == '('))
                return false;
            if (str[i] == ']' && (str[i - 1] == '{' || str[i - 1] == '('))
                return false;
            if (str[i] == ')' && (str[i - 1] == '[' || str[i - 1] == '{'))
                return false;
            if (str[i] == '}')
                x--;
            if (str[i] == ']')
                z--;
            if (str[i] == ')')
                y--;
        }
        if (x < 0 || y < 0 || z < 0)
            return false;
    }
    return (x == 0 && y == 0 && z == 0);
}

int main() {
    string s;
    cin >> s;
    cout << is_str_valid(s) << endl;
}
