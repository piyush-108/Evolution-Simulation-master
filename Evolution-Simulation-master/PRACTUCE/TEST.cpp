#include <iostream>
using namespace std;

string identifyComments(char c1, char c2)
{
    if (c1 == '/' && c2 == '/')
    {
        return "Single-line comment";
    }
    else if (c1 == '/' && c2 == '*')
    {
        return "Start of multi-line comment";
    }
    else if (c1 == '*' && c2 == '/')
    {
        return "End of multi-line comment";
    }
    return "";
}

string Rcomments(string s, string &comments)
{
    int n = s.length();
    string ans;
    bool single_c = false;
    bool multi_c = false;
    for (int i = 0; i < n; i++)
    {
        if (single_c == true && s[i] == '\n')
        {
            single_c = false;
            comments += "\n";
        }
        else if (multi_c == true && s[i] == '*' && s[i + 1] == '/')
        {
            multi_c = false, i++;
            comments += "*/";
        }
        else if (single_c || multi_c)
        {
            comments += s[i];
            continue;
        }
        else if (s[i] == '/' && s[i + 1] == '/')
        {
            single_c = true, i++;
            comments += "//";
        }
        else if (s[i] == '/' && s[i + 1] == '*')
        {
            multi_c = true, i++;
            comments += "/*";
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    string s, comments;

    cout << "Enter The String 1 : " << endl;
    getline(cin, s);
    cout << "Output : " << Rcomments(s, comments) << endl;
    cout << "Comments identified: " << comments << endl;

    cout << "Enter The String 2 : " << endl;
    getline(cin, s);
    cout << "Output : " << Rcomments(s, comments) << endl;
    cout << "Comments identified: " << comments << endl;

    return 0;
}