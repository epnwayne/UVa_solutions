#include<bits/stdc++.h>

using namespace std;
/*
    status: AC
    URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=668
*/

#define SIZE 50

int main()
{
    ofstream   file("ans.txt");
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n > 0)
    {
        string temp;
        char str[SIZE] = {0};
        int i = 0;
        while(1)
        {
            getline(cin, temp);
            str[i] = temp[0];
            if(temp == "")
                break;
            ++i;
        }

        stack<char> s1, s2;
        s1.push('#');
        i = 0;
        while(1)
        {   
            if(isdigit(str[i]))
            {
                s2.push(str[i]);
            }
            else if(str[i] == '(')
            {
                s1.push(str[i]);
            }
            else if(str[i] == '*' || str[i] == '/')
            {
                if(s1.top() == '*' || s1.top() == '/')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(str[i]);
            }
            else if(str[i] == '+' || str[i] == '-')
            {
                while(s1.top() == '*' || s1.top() == '/')
                {
                    s2.push(s1.top());
                    s1.pop();
                    if(s1.top() == '#')
                        break;
                }
                if(s1.top() == '+' || s1.top() == '-')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(str[i]);
            }
            else if(str[i] == ')')
            {
                while(s1.top() != '(')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.pop();
            }

            else if(str[i] == '\0')
            {
                while(s1.top() != '#')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                break;
            }
            ++i;
        }
        stack<char> ans;
        while(!s2.empty())
        {
            ans.push(s2.top());
            s2.pop();
        }
        
        while(!ans.empty())
        {
            file << ans.top();
            cout << ans.top();
            ans.pop();
        }   
        if(n == 1)
        {
            file << endl;
            cout << endl;
        }
        else
        {
            file << endl << endl;
            cout << endl << endl;            
        }
        
        --n;
    }

    return 0;
}