#include <bits/stdc++.h>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define ll long long
#define pi pair<ll, ll>

using namespace std;
const ll md = 1000000007;

/*
Idea: Keep track of which numbers have been placed using a set, and of numbers that have not been placed using a max heap. 
If snackSize + 1 has been placed, then you can place snackSize. 
TIP: You can use an unordered_set to make the overall speed a bit better since its functions are O(1). Also, this can be implemented with just two arrays.

*/
int main()
{
    int n;
    cin >> n;
    priority_queue<int> unplaced;
    set<int> placed;
    for (int i = 0; i < n; i++)
    {
        int snackSize;
        cin >> snackSize;
        if (placed.count(snackSize + 1) || snackSize == n)
        {
            cout << snackSize << " ";
            placed.insert(snackSize);
            while (!unplaced.empty() && placed.count(unplaced.top() + 1))
            {
                cout << unplaced.top() << " ";
                placed.insert(unplaced.top());
                unplaced.pop();
            }
        }
        else
        {
            unplaced.push(snackSize);
        }
        cout << "\n";
    }
    return 0;
}