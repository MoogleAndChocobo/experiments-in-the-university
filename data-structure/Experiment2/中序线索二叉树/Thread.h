#ifndef THREAD_H
#define THREAD_H

#include <iostream>

using namespace std;
typedef char DataType;

typedef struct Node
{
    DataType data;
    int      Ltag;
    int      Rtag;
    Node* LChild;   /*���1��ָ�������������*/
    Node* RChild;
}BTNode;

BTNode *pre;
void CreateBiTree(BTNode  *&root, DataType Array[]) ; //������ʼ��������
void  Inthread(BTNode *root); //ʵ����������������
BTNode * InPre(BTNode *p);  //��������������������ǰ��
BTNode * InNext(BTNode * p) ; //�������������������ĺ���


#endif // THREAD_H
