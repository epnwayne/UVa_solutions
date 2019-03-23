#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;

    for(int i = 0; i < n; i++)
        q.push(i+1);

//    cout << q.size();
    cout << "Discarded cards: ";
    while(q.size() != 1)
    {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << endl;
    cout << "Remaining card: " << q.front() << endl;

    return 0;
}