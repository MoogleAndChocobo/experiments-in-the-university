#ifndef UFS_H
#define UFS_H

#include <algorithm>

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


#endif // UFS_H
