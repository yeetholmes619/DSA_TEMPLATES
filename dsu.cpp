#include <iostream>
using namespace std;
const int sz = 100000;
class dsu
{
        int parent[sz] = {0};
        int rank[sz] = {0};

public:
        dsu(int n)
        {
                for (int i = 0; i < n; i++)
                {
                        parent[i + 1] = i + 1;
                }
        }
        int findParent(int node)
        {
                if (parent[parent[node]] == parent[node])
                        return parent[node];
                else
                {
                        parent[node] = findParent(parent[node]);
                        rank[parent[node]]++;
                        return parent[node];
                }
        }
        void Union(int a, int b)
        {
                if (rank[a] == rank[b])
                {
                        parent[parent[b]] = parent[a];
                        rank[a]++;
                }
                else if (rank[a] > rank[b])
                {
                        parent[parent[b]] = parent[a];
                        rank[a]++;
                }
                else
                {
                        parent[parent[a]] = parent[b];
                        rank[b]++;
                }
        }
};
int main()
{
}
