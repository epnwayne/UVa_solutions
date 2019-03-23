#include<bits/stdc++.h>
using namespace std;

/*
    status: AC
    Question URL:https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1842
*/

int main()
{
    int c;
    cin >> c;
    ofstream file("ans.txt");
    while(c > 0)
    {
        int n, t, m;
        cin >> n >> t >> m;
        queue<int> q;
        queue<string> loc;
        for(int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            q.push(temp);
            string  s;
            cin >> s;
            loc.push(s);  
        }
        queue<int> lq, lq_se;//left queue,   left queue series
        queue<int> rq, rq_se;
        vector<int> ans(m);

        int tc = 0;//time counter
        string l = "left";
        int load = 0;
        int order = 0;
        int ans_num = 0;
        while(1)
        {
            while(q.front() <= tc   &&    !q.empty())
            {
                if(loc.front() == "left")
                {
                    //cout << "load left!\n";
                    lq.push(tc);
                    lq_se.push(order);
                    ++order;
                    q.pop();
                    loc.pop();
                }
                else
                {
                    //cout << "load right!\n";
                    rq.push(tc);
                    rq_se.push(order);
                    ++order;
                    q.pop();
                    loc.pop();
                }
            }
            if(l == "left"  &&  !lq.empty())
            {
                while(!lq.empty()  &&   load != n)
                {
                    ans[lq_se.front()] = tc + t;
                    ++load;
                    lq.pop();
                    lq_se.pop();
                    l = "right";
                    ++ans_num;
                }
                tc += t;
                load = 0;
            }
            else if(l == "right"  &&  !rq.empty())
            {
                while(!rq.empty()  &&   load != n)
                {
                    ans[rq_se.front()] = tc + t;
                    ++load;
                    rq.pop();
                    rq_se.pop();
                    l = "left";
                    ++ans_num;
                }
                load = 0;
                tc += t;
            }
            else if(l == "left"  &&  !rq.empty())
            {
                tc += t;
                l = "right";
            }
            else if(l == "right"  &&   !lq.empty())
            {
                tc += t;
                l = "left";
            }
            else
            {
                ++tc;
            }
            
            if(ans_num == m)
                break;
        }

        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
            file << ans[i] << endl;
        }
        if(c != 1)
            cout << endl;
        --c;
    }

    return 0;
}