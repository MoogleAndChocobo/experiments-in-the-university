#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <algorithm>

#include "ufs.h"
#include "edge.h"
#include "orderedpairs.h"

using namespace std;


// Kruskal算法求MST
class Kruskal
{
public:
    Kruskal(int scale);

    // 初始化所有边
    void Init(int scale);

    // 插入有向边
    void AddEdge(int begin, int end, int  edgevalue);

    // 求MST所有边
    vector<OrderedPairs> Solve();


private:
    vector<Edge> storeedges_;  // 有向边集合
    Ufs uoperate_;  // 节点的并查集
    int scale_;  // 节点规模
};



Kruskal::Kruskal(int scale)
{
    scale_ = scale;
}

// 初始化所有边
void Kruskal::Init(int scale)
{
    scale_ = scale;
    storeedges_.clear();
}


// 插入有向边
void Kruskal::AddEdge(int begin, int end, int edgevalue)
{
    storeedges_.push_back(Edge(begin, end, edgevalue));
}


// 求最小生成树所有边
vector<OrderedPairs> Kruskal::Solve()
{
    int count = 0;  // 最小生成树已包含的节点个数
    int edgesize = storeedges_.size(); // 边的规模

    uoperate_.Init(scale_);
    vector<OrderedPairs> pairs;
    sort(storeedges_.begin(), storeedges_.end());  // 按权值排序所有边

    for (int tmpindex = 0; tmpindex < edgesize; ++tmpindex)
    {
        if(uoperate_.UnitePoint(storeedges_[tmpindex].begin_, storeedges_[tmpindex].end_))
        {
            count++;
            pairs.push_back(OrderedPairs(storeedges_[tmpindex].begin_, storeedges_[tmpindex].end_));
        }
        if(count == scale_ - 1)  // 已包含所有节点
            break;
    }
    return pairs;
}

#endif // KRUSKAL_H
