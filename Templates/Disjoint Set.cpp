#include <bits/stdc++.h>
using namespace std;
const int mX = 1e5;
int parent[mX];
int size[mX];


    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
