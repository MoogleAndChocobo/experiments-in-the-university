#include <iostream>
#include <stack>

#include "kruskal.h"
#include "macro.h"
#include "orderedpairs.h"

using namespace std;


void AdjacencyMatrix();
void AdjacencyList();
void DfsST();
void BfsST();
void SubDfsST(vector<OrderedPairs>& res, vector<vector<int> > graph, vector<bool>& isvisited,
              int beginnode, int& isvisitedcount, int pointsize, bool& checkres);

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

    return 0;
}


// 邻接矩阵输入求MST
void AdjacencyMatrix()
{
    int pointsize;
    cout << ">邻接矩阵输入方式<" << endl;
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
    cout << endl << endl << endl;
}


// 邻接表输入求MST
void AdjacencyList()
{
    cout << ">邻接表输入方式<" << endl;
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
    cout << endl;
}


// dfs回溯函数
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
    cout << ">dfs遍历,邻接矩阵输入方式<" << endl;
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

}


// bfs遍历图获得ST,邻接矩阵输入
void BfsST()
{
    cout << ">bfs遍历,邻接矩阵输入方式<" << endl;
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
    /*
    isvisited[beginnode-1] = true; // 将起始节点压入生成树节点中
    int isvisitedcount = 1; // 已经存在于ST中节点的个数
    bool checkres = false; // 标记未找到ST
    SubDfsST(res, graph, isvisited, beginnode-1, isvisitedcount, pointsize, checkres); // dfs
    */



    // 输出结果
    int ressize = res.size();
    for (int i = 0; i < ressize; ++i)
    {
        cout << "(" << res[i].begin_ << "," << res[i].end_ << ")   ";
    }
}
