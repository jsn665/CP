struct UF{
    static const int mX = 1e5;
    int parent[mX];
    int sz[mX];


    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void make(int u)
    {
        parent[u] = u;
        sz[u] = 1;
    }

    void union_sets(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};
