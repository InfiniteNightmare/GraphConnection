#include <iostream>
#include <queue>
#include <vector>

#define UDG 0
#define DG 1

class Graph
{
private:
    int n;                                // 顶点数
    int density;                          // 密度
    bool type;                            // 图的类型，0:无向图，1:有向图
    bool is_connected = false;            // 是否连通
    bool is_strongly_connected = false;   // 是否强连通
    bool is_unilateral_connected = false; // 是否单侧连通
    bool is_weakly_connected = false;     // 是否若连通
    std::vector<std::vector<bool>> graph; // 邻接矩阵
    void parseGraph();                    // 解析邻接矩阵，判断图的连通性

public:
    Graph(bool _type, int _n, int _density = 50); // 根据参数随即生成邻接矩阵
    Graph();                                      // 默认构造函数，从文件中读取邻接矩阵
    void printGraph();                            // 输出邻接矩阵
    void printAttr();                             // 输出图的连通性
};