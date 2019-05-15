#ifndef EDGE_H
#define EDGE_H

// 边
struct Edge
{
    int begin_;
    int end_;
    int  edgevalue_;
    Edge(int begin = 0, int end = 0, int  edgevalue = -1):begin_(begin), end_(end),  edgevalue_(edgevalue){}
    friend bool operator< (Edge first, Edge second)
    {
        return first. edgevalue_ < second. edgevalue_;
    }
};

#endif // EDGE_H
