#include <iostream>
using namespace std;

#define _print(a)        \
        for (auto t : a) \
        cout << t << " "
using namespace std;
int n;
int ar[1000000];
template <class T>
void p(T a[], int n)
{
        cout << "***";
        for (int i = 0; i < n; i++)
                cout << a[i] << " ";
        cout << "\n";
}
template <class T>
void pp(T a[], int st, int en)
{
        for (int i = st; i <= en; i++)
                cout << a[i] << " ";
        cout << "\n";
}
template <class T>
void merge(T arr[], int s, int m, int e)
{
        T a1[100005];
        T a2[100005];
        int i1 = 0, i2 = 0;
        for (int i = s; i <= m; i++)
        {
                a1[i - s] = arr[i];
        }
        for (int i = m + 1; i <= e; i++)
        {
                a2[i - m - 1] = arr[i];
        }
        int i;
        for (i = s; ((i1 < m - s + 1) and (i2 < e - m)); i++)
        {
                if (a1[i1].w <= a2[i2].w)
                {
                        arr[i] = a1[i1];
                        i1++;
                }
                else
                {
                        arr[i] = a2[i2];
                        i2++;
                }
        }
        while (i1 < m - s + 1)
        {
                arr[i] = a1[i1];
                i1++;
                i++;
        }
        while (i2 < e - m)
        {
                arr[i] = a2[i2];
                i2++;
                i++;
        }
}
template <class T>
void mergesort(T arr[], int start, int end)
{
        if (end <= start)
                return;
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
}
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

class node
{
public:
        int data;
        node *next;
        node()
        {
                next = NULL;
        }
};

class Queue
{
public:
        node *head;
        node *tail;
        void enqueue(int value);
        int size;
        void dequeue();
        void printer();
        int front();
        void rear();
        Queue()
        {
                head = NULL;
                tail = NULL;
                size = 0;
        }
};
int Queue::front()
{
        return head->data;
}
void Queue::rear()
{
        cout << tail->data << "\n";
}
void Queue::enqueue(int value)
{
        size++;
        node *temp = new node;
        temp->data = value;
        if (head == NULL)
        {
                head = temp;
                tail = temp;
        }
        else
        {
                tail->next = temp;
                tail = tail->next;
        }
}
void Queue::dequeue()
{
        size--;
        head = head->next;
}
void Queue::printer()
{
        node *temp = head;
        while (temp != NULL)
        {
                cout << temp->data << " ";
                temp = temp->next;
        }
        cout << "\n";
}
const int NODE_SIZE = 100;
const int NEIGHBOUR_SIZE = 100;
class graph
{
public:
        int n, m;
        int adj[NODE_SIZE][NEIGHBOUR_SIZE] = {0};
        int weight[NODE_SIZE][NODE_SIZE] = {0};
        int degree[NODE_SIZE] = {0};
        int visited[NODE_SIZE] = {0};
        graph()
        {
                n = 0;
                m = 0;
                for (int i = 0; i < NODE_SIZE; i++)
                {
                        for (int j = 0; j < NODE_SIZE; j++)
                        {
                                weight[i][j] = 10000;
                        }
                }
        }
        void addEdge(int a, int b, int w)
        {
                n += (degree[a] == 0);
                n += (degree[b] == 0);
                adj[a][degree[a]] = b;
                degree[a]++;
                weight[a][b] = min(weight[a][b], w);
                weight[b][a] = min(weight[b][a], w);
        }
        void dfs(int a = 1)
        {
                cout << a << " ";
                visited[a] = 1;
                for (int i = 0; i < degree[a]; i++)
                {
                        if (!visited[adj[a][i]])
                                dfs(adj[a][i]);
                }
        }
        bool hasCycle(int a = 1, int parent = -1)
        {
                //                        cout<<a<<" ";
                visited[a] = 1;
                for (int i = 0; i < degree[a]; i++)
                {
                        if (!visited[adj[a][i]])
                        {
                                if (hasCycle(adj[a][i], a))
                                        return true;
                        }
                        else if (adj[a][i] != parent)
                                return true;
                }
                return false;
        }
        void bfs(int a = 1)
        {
                cout << a << " ";
                visited[a] = 1;
                Queue q;
                q.enqueue(a);
                while (q.size)
                {
                        int t = q.front();
                        q.dequeue();
                        for (int i = 0; i < degree[t]; i++)
                        {
                                if (!visited[adj[t][i]])
                                {
                                        cout << adj[t][i] << " ";
                                        q.enqueue(adj[t][i]);
                                        visited[adj[t][i]] = 1;
                                }
                        }
                }
        }
};
struct edge
{
        int a, b, w;
        edge()
        {
                a = 0;
                b = 0;
                w = 0;
        }
};
void kruskal(graph g, edge e[], int &n)
{
        edge given[100000];
        int ng = 0;
        for (int i = 1; i <= g.n; i++)
        {
                for (int j = 0; j < g.degree[i]; j++)
                {
                        given[ng].a = i;
                        given[ng].b = g.adj[i][j];
                        given[ng].w = g.weight[i][g.adj[i][j]];
                        ng++;
                }
        }

        mergesort(given, 0, ng - 1);
       // for(int i =0 ; i < ng; i++){
       //         cout<<given[i].a <<" "<<given[i].b<<" "<<given[i].w<<"\n";
       // }
       // cout<<"\n";
        n = 0;
        dsu d(g.n);
        for (int i = 0; i < ng; i++)
        {
                if (d.findParent(given[i].a) != d.findParent(given[i].b))
                {
                        e[n] = given[i];
                        n++;
                        d.Union(given[i].a, given[i].b);
                }
        }
}
int main()
{
        int n, m;
        cin >> n >> m;
        graph g;
        for (int i = 0; i < m; i++)
        {
                int a, b, w;
                cin >> a >> b >> w;
                a++;
                b++;
                g.addEdge(a, b, w);
                g.addEdge(b, a, w);
        }
        edge ans[10000];
        int si = 0;
        kruskal(g, ans, si);
        int mst = 0;
        for (int i = 0; i < si; i++)
        {
//                cout << ans[i].a << " " << ans[i].b << " " << ans[i].w << "\n";
                mst += ans[i].w;
        }
        cout << mst;
}
