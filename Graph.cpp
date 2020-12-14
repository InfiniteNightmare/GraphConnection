#include "Graph.h"

Graph::Graph()
{
    int i, j;
    bool temp;
    std::cin >> type >> n;
    graph.resize(n);
    for (i = 0; i < n; ++i)
    {
        graph[i].resize(n);
        for (j = 0; j < n; ++j)
        {
            std::cin >> temp;
            graph[i][j] = temp;
        }
    }
    parseGraph();
}

Graph::Graph(bool _type, int _n, int _density)
{
    type = _type;
    n = _n;
    density = _density;
    int i, j;
    int odds;
    graph.resize(n);
    if (type == DG) // 有向图的生成
    {
        for (i = 0; i < n; ++i)
        {
            graph[i].resize(n);
            for (j = 0; j < n; ++j)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                {
                    // 不等概率产生01值
                    odds = rand() % 100;
                    if (odds < density)
                        graph[i][j] = 1;
                    else
                        graph[i][j] = 0;
                }
            }
        }
    }
    if (type == UDG) // 无向图的生成
    {
        for (i = 0; i < n; ++i)
        {
            graph[i].resize(n);
            for (j = 0; j < i; ++j)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                {
                    // 不等概率产生01值
                    odds = rand() % 100;
                    // 无向图的邻接矩阵是对称矩阵
                    if (odds < density)
                        graph[i][j] = graph[j][i] = 1;
                    else
                        graph[i][j] = graph[j][i] = 0;
                }
            }
        }
    }
    parseGraph();
}

// BFS
void Graph::parseGraph()
{
    int v, u, i;
    int counter;
    std::queue<int> queue;
    std::vector<bool> visited(n, 0);
    counter = 0;
    queue.push(0);
    while (!queue.empty())
    {
        v = queue.front();
        visited[v] = true;
        queue.pop();
        ++counter;
        for (u = 0; u < n; ++u)
        {
            if (!visited[u] && ((type == UDG && graph[v][u]) || (type == DG && (graph[v][u] || graph[u][v]))))
            {
                queue.push(u);
                visited[u] = true;
            }
        }
    }
    if (counter == n)
    {
        if (type == UDG)
            is_connected = true;
        if (type == DG)
            is_weakly_connected = true;
    }
    if (type == DG)
    {
        is_strongly_connected = true;
        for (i = 0; i < n; ++i)
        {
            visited.assign(n, 0);
            counter = 0;
            queue.push(i);
            while (!queue.empty())
            {
                v = queue.front();
                queue.pop();
                visited[v] = true;
                ++counter;
                for (u = 0; u < n; ++u)
                {
                    if (!visited[u] && graph[v][u])
                    {
                        queue.push(u);
                        visited[u] = true;
                    }
                }
            }
            if (counter != n)
                is_strongly_connected = false;
            else
                is_unilateral_connected = true;
        }
    }
}

void Graph::printGraph()
{
    std::cout << "邻接矩阵为：" << std::endl;
    for (auto i : graph)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printAttr()
{
    if (type == UDG)
    {
        if (is_connected)
            std::cout << "具有连通性" << std::endl;
        else
            std::cout << "不具有连通性" << std::endl;
    }
    else
    {
        if (is_strongly_connected)
            std::cout << "具有强连通性" << std::endl;
        else if (is_unilateral_connected)
            std::cout << "具有单侧连通性" << std::endl;
        else if (is_weakly_connected)
            std::cout << "具有弱连通性" << std::endl;
        else
            std::cout << "不具有连通性" << std::endl;
    }
}