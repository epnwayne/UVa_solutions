#include<bits/stdc++.h>

using namespace std;

/*
    status: AC
    Question URL:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
*/


int main()
{
    int n;
    cin >> n;
    string str; 
    cin.ignore();

    ofstream file("ans.txt");
    while(n > 0)
    {
        getline(cin, str);
        //cin.ignore();
        if(str[0] == '\n')
            cout << "Yes" << endl;
        else
        {
            int ls = 0, rs = 0, lm = 0, rm = 0;
            int flag = 0;
            for(int i = 0; i < str.length(); i++)
            {
                if(str[i] == '(')       ls++;
                else if(str[i] == ')')  
                {  
                    rs++;
                    int l = 0, r = 0;
                    int t = 0;
                    for(int j = i; j >= 0; j--)
                    {
                        if(str[j] == ')') t++;
                        if(str[j] == '(')
                        {
                            t--;
                            if(t == 0)
                                break;
                        }
                        if(str[j] == '[') l++;
                        if(str[j] == ']') r++;
                        if(l > r)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(l != r)
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(str[i] == '[')  lm++;
                else             
                {
                    rm++;
                    int l = 0, r = 0;
                    int t = 0;
                    for(int j = i; j >= 0; j--)
                    {
                        if(str[j] == ']') t++;
                        if(str[j] == '[')
                        {
                            t--;
                            if(t == 0)
                                break;
                        }
                        if(str[j] == '(') l++;
                        if(str[j] == ')') r++;
                        if(l > r)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(l != r)
                    {
                        flag = 1;
                        break;
                    }
                }

                if(rs > ls || rm > lm)
                {
                    flag = 1;
                    break;
                }
            }

            if(ls == rs && lm == rm && flag == 0)
            {
                file << "Yes\n"; 
                cout << "Yes" << endl;
            }
            else
            {
                file << "No\n";
                cout << "No" << endl;
            }   
        }
        str.clear();
        --n;
    }
    return 0;
}

