# 基于邻接矩阵的图的连通性判断

## 前言

在离散数学图论的学习中，老师布置了一个作业，用程序判断图（包括无向图和有向图）的连通性。由于在数据结构中已经学过图这种数据结构的存储及其基本的遍历算法，而且图的连通性的定义简单，判断图的连通性也相对比较简单。

## 基本知识

### 无向连通图

若无向图G任意两个结点之间至少存在一条路，则称G是连通图。

### 有向强连通图

在简单有向图G中，任何一对结点间，至少有一个结点到另一个结点是相互可达的，则称这个图是强连通的。

### 有向单侧连通图

在简单有向图G中，任何一对结点间，至少有一个结点到另一个结点是可达的，则称这个图是单侧连通的。

### 有向弱连通图

在简单有向图G中，略去边的方向，将它看成无向图后，图是连通的，则称该图为弱连通的。

## 数据结构说明

图的存储采用邻接矩阵，具体用C++STL的std::vector，在数组的基础上提供了一系列方法，并能保证内存的安全性。

#### 类声明

```c++
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
```



## 算法

### 无向图的连通性判断

从任意一个顶点开始，如果能遍历所有顶点，则该图为连通图。

### 有向图的强连通性判断

从任意一个顶点开始，如果都能遍历所有顶点，则该图为连通图。

### 有向图的单侧连通性判断

如果存在一个顶点，从该顶点开始能遍历所有顶点，则该图为连通图。

### 有向图的弱连通性判断

将有向图转化为无向图，若该无向图是连通图，则原有向图为弱连通图，即在无向图的连通性判断算法中忽略边的方向，在邻接矩阵对称位置的值有1则认为对应的两个顶点间有边。

### 图的遍历

图的基本遍历方法分为DFS和BFS，本程序统一使用BFS。

BFS使用了队列存储当前与顶点邻接的顶点，并用visited数组记录是否访问过顶点，每次从队头取出顶点进行访问，并将与该顶点邻接且未访问过的顶点放入队尾，直到队空。

由于图采用邻接矩阵进行存储，因此时间复杂度为$O(n^2)$

### 具体算法实现

无向图的连通性判断是先将第一个顶点放入队列中进行BFS，若遍历结束所有顶点都被访问过则该图为连通图。

有向图的强连通性判断是用循环依次将每一个顶点放入队列中进行BFS，若从每一个顶点开始的BFS遍历结束后所有顶点都被访问过则该图为强连通图。

有向图的单侧连通性判断是先将第一个顶点放入队列中进行BFS，若遍历结束所有顶点都被访问过则该图为单侧连通图。

有向图的弱连通性判断是先将第一个顶点放入队列中进行忽略边的方向的BFS，若遍历结束所有顶点都被访问过则该图为弱连通图。

为了提高算法效率，将无向图的连通性判断和有向图的弱连通性判断在一次BFS中进行，将有向图的强连通性判断和单侧连通性判断在另一次BFS中进行。这样有向图的连通性判断最多进行两次BFS。

## 实例演示

#### 演示一：随机生成无向图

##### 演示代码：

```c++
    Graph graph(UDG, 6);
    graph.printGraph();
    graph.printAttr();
```

##### 输出：

![image-20201214195905614](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214195905614.png)

#### 演示二：随机生成有向图

##### 演示代码：

```c++
    Graph graph(DG, 8， 60);
    graph.printGraph();
    graph.printAttr();
```

##### 输出：

![image-20201214200247783](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214200247783.png)

#### 演示三：无向连通图

##### 演示代码：

```c++
    Graph graph();
    graph.printGraph();
    graph.printAttr();
```

##### 输入：

![image-20201214201220503](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201220503.png)

##### 输出：

![image-20201214201233061](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201233061.png)

#### 演示四：有向强连通图

##### 演示代码：

```c++
    Graph graph();
    graph.printGraph();
    graph.printAttr();
```

##### 输入：

![image-20201214201428919](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201428919.png)

##### 输出：

![image-20201214201441382](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201441382.png)

#### 演示五：有向单侧连通图

##### 演示代码：

```c++
    Graph graph();
    graph.printGraph();
    graph.printAttr();
```

##### 输入：

![image-20201214201327413](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201327413.png)

##### 输出：

![image-20201214201341418](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201341418.png)

#### 演示六：有向弱连通图

##### 演示代码：

```c++
    Graph graph();
    graph.printGraph();
    graph.printAttr();
```

##### 输入：

![image-20201214201608346](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201608346.png)

##### 输出：

![image-20201214201623229](https://gitee.com/InfiniteNightmare/album/raw/master/img/image-20201214201623229.png)

## 总结

本次作业难度简单，前后一共花了几个小时就完成了，代码的行数也不多。但在研究算法的过程中深感图论博大精深，但本次作业只涉及了一点点皮毛，用的算法也是最原始的遍历算法。在查找资料的过程中也发现了一些效率更加高的算法，涉及了图的更多知识，只是限于时间有限，匆匆完成了题目的要求，对这些算法没有仔细研究下去，留下一些遗憾。