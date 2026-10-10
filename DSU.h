#ifndef DSU_H
#define DSU_H

#include <vector>

using namespace std;

class DSU
{
private:
    vector<int> parent;

public:

    DSU(int n)
    {
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB)
        {
            parent[rootB] = rootA;
        }
    }
};

#endif