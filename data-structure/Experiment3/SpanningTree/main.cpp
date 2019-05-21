/**
  * C++: ST
  *
  * @author MoogleAndChocobo
  * @date 2019/05/15
  */

#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include "kruskal.h"
#include "macro.h"
#include "orderedpairs.h"
#include "edge.h"
#include "ufs.h"

using namespace std;


void AdjacencyMatrix(); // 邻接矩阵输入求MST
void AdjacencyList(); // 邻接表输入求MST
void DfsST(); // dfs遍历图获得ST，邻接矩阵输入
void BfsST(); // bfs遍历图获得ST,邻接表输入
void SpanningForest(); // 求非连通图的生成森林,邻接矩阵输入
void SubDfsST(vector<OrderedPairs>& res, vector<vector<int> > graph, vector<bool>& isvisited,
              int beginnode, int& isvisitedcount, int pointsize, bool& checkres); // dfs回溯
vector<OrderedPairs> SubBfsST(); // bfs队列操作
void Format();


int main()
{

    // 邻接矩阵输入求MST
    AdjacencyMatrix();

    // 邻接表输入求MST
    AdjacencyList();

    // dfs遍历图获得ST,邻接矩阵输入
    DfsST();

    // bfs遍历图获得ST,邻接矩阵输入
    BfsST();

    // 求非连通图的生成森林，邻接矩阵输入
    SpanningForest();

    return 0;
}


// 分割ST的输出
void Format()
{
    cout << endl << endl << "--------------------------" << endl << endl;
}

// 邻接矩阵输入求MST
void AdjacencyMatrix()
{
    int pointsize;
    cout << ">邻接矩阵输入求MST<" << endl;
    cout << "-->请输入节点个数:";
    cin >> pointsize; // 节点个数
    Kruskal koperate(pointsize);
    cout << "-->请输入邻接矩阵:" << endl;
    for (int rowindex = 0; rowindex < pointsize; ++rowindex)
    {
        for (int columnindex = 0; columnindex < pointsize; ++columnindex)
        {
            int edgevalue = 0; // 权值
            cin >> edgevalue;

            if(edgevalue != -1)
            {
                koperate.AddEdge(rowindex+1,columnindex+1,edgevalue); //插边
            }
        }
    }

    vector<OrderedPairs> res = koperate.Solve(); // MST中边的节点构成的序偶对,即输出结果

    int ressize = res.size();
    for (int i = 0; i < ressize; ++i)
    {
        cout << "(" << res[i].begin_ << "," << res[i].end_ << ")   ";
    }

    Format();
}


// 邻接表输入求MST
void AdjacencyList()
{
    cout << ">邻接表输入求MST<" << endl;
    cout << "-->请输入节点个数:";
    int pointsize = 0; // 节点个数
    cin >> pointsize;

    Kruskal koperate(pointsize);
    koperate.Init(pointsize);
    for (int rowindex = 0; rowindex < pointsize; ++rowindex)
    {
        cout << "-->请输入以节点" << rowindex+1 << "为起点的邻接边边数:";
        int columnsize = 0; // 邻接边边数
        cin >> columnsize;
        for(int columnindex = 0; columnindex < columnsize; ++columnindex)
        {
            cout << "-->请输入节点" << rowindex+1 << "第" << columnindex+1 << "条邻接边的终点和权值:";
            int end = 0; // 邻接边终点
            int edgevalue = 0; // 权值
            cin >> end >> edgevalue;
            if(edgevalue != -1)
            {
                koperate.AddEdge(rowindex+1,end,edgevalue); //插边
            }
        }
        cout << endl;
    }

    vector<OrderedPairs> res = koperate.Solve(); // MST中边的节点构成的序偶对,即输出结果

    int ressize = res.size();
    for (int i = 0; i < ressize; ++i)
    {
        cout << "(" << res[i].begin_ << "," << res[i].end_ << ")   ";
    }
    Format();
}


// dfs回溯
void SubDfsST(vector<OrderedPairs>& res, vector<vector<int> > graph, vector<bool>& isvisited,
              int beginnode, int& isvisitedcount, int pointsize, bool& checkres)
{

    if(isvisitedcount == pointsize) // ST已找到,结束递归
    {
        checkres = true;
        return;
    }

    for(int endnode = 0; endnode < pointsize; ++endnode) // 回溯法寻找ST
    {
        if(beginnode == endnode || isvisited[endnode] || graph[beginnode][endnode] == -1)
            continue; // 跳过节点自身,已经存在于ST中的节点,不存在的边

        res.push_back(OrderedPairs(beginnode+1, endnode+1)); // 将已找到的边存入序偶对数组中
        ++isvisitedcount;
        isvisited[endnode] = true; // 标记访问过的节点为true
        SubDfsST(res, graph, isvisited, endnode, isvisitedcount, pointsize, checkres);

        if(checkres) // ST已找到,结束递归
            return;

        --isvisitedcount; // 回溯到上一阶段
        res.pop_back();
        isvisited[endnode] = false;
    }
}


// dfs遍历图获得ST,邻接矩阵输入
void DfsST()
{
    cout << ">dfs遍历图获得ST,邻接矩阵输入<" << endl;
    cout << "-->请输入节点个数:";
    int pointsize; // 节点个数
    cin >> pointsize;

    vector<vector<int> > graph; // 存图
    vector<bool> isvisited(pointsize); // 判断节点是否访问过

    cout << "-->请输入邻接矩阵:" << endl;
    for (int rowindex = 0; rowindex < pointsize; ++rowindex)
    {
        vector<int> tmprow;
        for (int columnindex = 0; columnindex < pointsize; ++columnindex)
        {
            int edgevalue = 0;  // 权值
            cin >> edgevalue;
            tmprow.push_back(edgevalue);
        }
        graph.push_back(tmprow);
    }

    int beginnode = 0; // 起始节点
    cout << "-->请输入起始节点:";
    cin >> beginnode;

    vector<OrderedPairs> res; // ST中边的节点构成的序偶对,即输出结果
    isvisited[beginnode-1] = true; // 将起始节点压入生成树节点中
    int isvisitedcount = 1; // 已经存在于ST中节点的个数
    bool checkres = false; // 标记未找到ST
    SubDfsST(res, graph, isvisited, beginnode-1, isvisitedcount, pointsize, checkres); // dfs

    // 输出结果
    int ressize = res.size();
    for (int i = 0; i < ressize; ++i)
    {
        cout << "(" << res[i].begin_ << "," << res[i].end_ << ")   ";
    }
    Format();

}

// bfs队列操作
vector<OrderedPairs> SubBfsST(vector<vector<int> > graph, int beginnode, int pointsize)
{
    vector<OrderedPairs> res;
    vector<bool> isvisited(pointsize,0);  // 记录节点是否已访问

    queue<int> qnode;  // 容纳节点的队列
    qnode.push(beginnode);
    int countpoint = 1;  // 已找到的节点个数
    isvisited[beginnode] = true; // 标记起始节点

    while(!qnode.empty())
    {
        int topnode = qnode.front(); // 取队首节点
        qnode.pop();
        for(int index = 0; index < pointsize; ++index)
        {
            if(index != topnode && !isvisited[index] && graph[topnode][index] != -1)
            {
                res.push_back(OrderedPairs(topnode+1,index+1));
                if(++countpoint == pointsize) // 已找到生成树,返回结果
                    return res;
                qnode.push(index); // 将队首节点未发现的邻居放入队列中
                isvisited[index] = true; // 标记已入队的节点
            }
        }
    }
    return res;

}


// bfs遍历图获得ST,邻接矩阵输入
void BfsST()
{
    cout << ">bfs遍历图获得ST,邻接矩阵输入<" << endl;
    cout << "-->请输入节点个数:";
    int pointsize; // 节点个数
    cin >> pointsize;

    vector<vector<int> > graph; // 存图
    vector<bool> isvisited(pointsize); // 判断节点是否访问过

    cout << "-->请输入邻接矩阵:" << endl;
    for (int rowindex = 0; rowindex < pointsize; ++rowindex)
    {
        vector<int> tmprow;
        for (int columnindex = 0; columnindex < pointsize; ++columnindex)
        {
            int edgevalue = 0;  // 权值
            cin >> edgevalue;
            tmprow.push_back(edgevalue);
        }
        graph.push_back(tmprow);
    }

    int beginnode = 0; // 起始节点
    cout << "-->请输入起始节点:";
    cin >> beginnode;

    vector<OrderedPairs> res = SubBfsST(graph, beginnode-1, pointsize); // ST中边的节点构成的序偶对,即输出结果

    // 输出结果
    int ressize = res.size();
    for (int i = 0; i < ressize; ++i)
    {
        cout << "(" << res[i].begin_ << "," << res[i].end_ << ")   ";
    }
    Format();
}


// 求非连通图的生成森林,邻接矩阵输入
void SpanningForest()
{
    int pointsize;
    cout << ">求非连通图的生成森林,邻接矩阵输入<" << endl;
    cout << "-->请输入节点个数:";
    cin >> pointsize; // 节点个数

    int adjacent_matrix[kMaxPoint][kMaxPoint] = {0}; // 存邻接矩阵
    vector<Edge> edges; // 存边
    cout << "-->请输入邻接矩阵:" << endl;
    for (int rowindex = 1; rowindex <= pointsize; ++rowindex)
    {
        for (int columnindex = 1; columnindex <= pointsize; ++columnindex)
        {
            int edgevalue = 0; // 权值
            cin >> edgevalue;
            adjacent_matrix[rowindex][columnindex] = edgevalue;
            if(edgevalue != -1)
                edges.push_back(Edge(rowindex, columnindex, edgevalue));
        }
    }

    Ufs count_connected_graph; // 使用并查集归类属于同一连通图的节点
    count_connected_graph.Init(pointsize);
    int edgesize = edges.size(); // 边规模
    for (int index = 0; index < edgesize; ++index) // 将所有边存入并查集
    {
        count_connected_graph.UnitePoint(edges[index].begin_, edges[index].end_);
    }
    vector<vector<int> > graphs = count_connected_graph.Classify();  // 得到通过并查集分类后的节点

    // 分别寻找连通图的MST
    int countgraph = graphs.size();
    for (int graphindex = 0; graphindex < countgraph; ++graphindex)
    {
        int graph_pointsize = graphs[graphindex].size();
        Kruskal koperate(graph_pointsize);
        for (int pointu = 0; pointu < graph_pointsize; ++pointu)
        {

            for (int pointv = 0; pointv < graph_pointsize; ++pointv)
            {
                int begin = graphs[graphindex][pointu];
                int end = graphs[graphindex][pointv];
                int value = adjacent_matrix[begin][end];
                if(pointu != pointv && value != -1)
                    koperate.AddEdge(pointu, pointv, value); // 插边
            }
        }

        vector<OrderedPairs> res = koperate.Solve(); // MST中,边的节点构成的序偶对,即输出结果

        // 分别输出构成连通图的ST的所有边上节点的序偶对
        int ressize = res.size();
        for (int i = 0; i < ressize; ++i)
        {
            int begin = graphs[graphindex][res[i].begin_];
            int end = graphs[graphindex][res[i].end_];
            cout << "(" << begin << "," << end << ")   ";
        }
        cout << endl;
    }
    Format();
}
