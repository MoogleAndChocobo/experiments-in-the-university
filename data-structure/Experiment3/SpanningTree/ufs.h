#ifndef UFS_H
#define UFS_H

#include <algorithm>
#include <set>
#include <map>

#include "macro.h"

using namespace std;

// 并查集
class Ufs
{
public:
    Ufs();

    // 初始化并查集,将所有集合的标志节点设为本身
    void Init(int scale);

    // 查询集合的标志节点
    int FindParent(int visit);

    // 判断两个节点是否存在于同一个集合,并合并两个集合
    bool UnitePoint(int first, int second);

    // 对节点按所属连通图分类
    vector<vector<int> > Classify();

private:
    int parent_[kMaxPoint];  // 标志节点
    int scale_;  // 节点规模

};

Ufs::Ufs()
{

}


// 初始化并查集,将所有集合的标志节点设为本身
void Ufs::Init(int scale)
{
    scale_ = scale;
    for (int tmpindex = 1; tmpindex <= scale_; ++tmpindex)
        parent_[tmpindex] = tmpindex;
}


// 查询集合的标志节点
int Ufs::FindParent(int visit)
{
    while(visit != parent_[visit])
        visit = parent_[visit];
    return visit;
}


// 判断两个节点是否存在于同一个集合,并合并两个集合
bool Ufs::UnitePoint(int first, int second)
{
    int firstparent = FindParent(first);
    int secondparent = FindParent(second);
    parent_[first] = parent_[second] = parent_[firstparent] = parent_[secondparent] = min(firstparent, secondparent);
    return firstparent != secondparent;
}

// 对节点按所属连通图分类
vector<vector<int> > Ufs::Classify()
{
    set<int> rescount; // 求连通图数量
    for (int index = 1; index <= scale_; ++index)
    {
        rescount.insert(FindParent(index));
    }

    map<int,int> signalpoints; // 依标志节点映射连通图所处位置
    vector<vector<int> > connectedgraph(rescount.size()); // 分类后的节点
    int graphindex = 1;
    for (int index = 1; index <= scale_; ++index)
    {
        int indexparent = FindParent(index);
        int parentgraph = signalpoints[indexparent]; // 查找标志节点所属连通图的位置
        if(parentgraph) // 连通图存在则压入节点,不存在则创建新连通图
            connectedgraph[parentgraph-1].push_back(index);
        else
        {
            connectedgraph[graphindex-1].push_back(index);
            signalpoints[indexparent] = graphindex++;
        }
    }


    return connectedgraph;
}

#endif // UFS_H
