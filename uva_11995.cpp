#include<bits/stdc++.h>
using namespace std;
/*
    date: 2019/3/16
    status: AC
    URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
*/

int main()
{
    ofstream   file("ans.txt");
    while(1)
    {
        int n;
        cin >> n;
        if(cin.eof())
            break;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int check[3] = {1, 1, 1}; //stack, queue, priority queue
        for(int i = 0; i < n; i++)
        {
            int command;
            cin >> command;
            if(command == 1)
            {
                int temp;
                cin >> temp;
                s.push(temp);
                q.push(temp);
                pq.push(temp);
            }
            else
            {
                int temp;
                cin >> temp;
                if(s.empty())
                    check[0] = 0;
                else   
                {
                    if(s.top() != temp) 
                        check[0] = 0;
                    s.pop();
                }
                if(q.empty())
                    check[1] = 0;
                else 
                {
                    if(q.front() != temp) 
                        check[1] = 0;
                    q.pop();
                }
                if(pq.empty())
                    check[2] = 0;
                else 
                {
                    if(pq.top() != temp) 
                        check[2] = 0;
                    pq.pop();
                }
            }
        }
        if(check[0] == 0 && check[1] == 0 && check[2] == 0)
        {
            cout << "impossible" << endl;
            file << "impossible" << endl;
        }
        else if(check[0] == 1 && check[1] == 0 && check[2] == 0)
        {
            cout << "stack" << endl;
            file << "stack" << endl;
        }
        else if(check[0] == 0 && check[1] == 1 && check[2] == 0)
        {
            cout << "queue" << endl;
            file << "queue" << endl;
        }
        else if(check[0] == 0 && check[1] == 0 && check[2] == 1)
        {
            cout << "priority queue" << endl;
            file << "priority queue" << endl;
        }
        else
        {
            cout << "not sure" << endl;
            file << "not sure" << endl;
        }
    }
    return 0;
}
