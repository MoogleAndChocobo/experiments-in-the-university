#include <iostream>

#include "thread.h"         /*11����գ�����գ�����ͷ�ļ�*/

using namespace std;

void CreateBiTree(BTNode *&root, DataType Array[])
{
    static int count=0;	//��̬����count
    char item=Array[count];//��ȡArray[]�����еĵ�count��Ԫ��
    count++;
    if(item == '#') //�������#�ַ�����������
       { root = NULL; return ;}
    else
    {
        root = new BTNode();/*���3������һ���½��*/
        root->data = item; /*���4����ch��Ϊ�½����������ֵ*/
        root->Ltag=0;
        root->Rtag=0;
        CreateBiTree(root->LChild, Array); /*���5: �ݹ�ķ�����������������ע��ʵ�εı�ʾ����*/
        CreateBiTree(root->RChild, Array); /*���6: �ݹ�ķ�����������������ע��ʵ�εı�ʾ����*/

     }
}

void  Inthread(BTNode *root)
/* ��root��ָ�Ķ�������������������������preʼ��ָ��շ��ʹ��Ľ�㣬���ֵΪNULL */
{
    if (root!=NULL)
    {
        Inthread(root->LChild);  /* ������������ */
        if (root->LChild==NULL)
        {
            root->Ltag=1;
            root->LChild=pre;  /*���7-8����ǰ������ */
        }
        if (pre!=NULL&& pre->RChild==NULL)  /* ���9-10���ú������ */
        {
            pre->Rtag=1;
            pre->RChild=root;
        }
       pre=root;
       Inthread(root->RChild);  /*������������*/
    }
}

/* �����������������в���p������ǰ��, ����preָ�뷵�ؽ�� */
BTNode * InPre(BTNode *p)
{
    BTNode *q;
    if(p->Ltag==1)
        pre = pre->LChild;  /*���13��ֱ������������ǰ��*/
    else
    { /* ���14-15����p���������в���"�����¶�"��� */
        for(q = p->LChild;q->Rtag==0;q=q->RChild);
        pre=q;
    }
    return(pre);
}

/*�����������������в���p�������̽�㣬����nextָ�뷵�ؽ��*/
BTNode * InNext(BTNode * p)
{
    BTNode *Next;
    BTNode *q;
    if (p->Rtag==1)
        Next = p->RChild;  /*���16��ֱ����������*/
    else
    { /*���17-18�� ��p���������в���"�����¶�"���*/
        for(q=p->RChild; q->Ltag==0 ;q=q->LChild);
        Next=q;
    }
    return(Next);
}

int main()
{
    BTNode *root,*q;
    DataType A[]="AB#CD##E##F#G##";//��"#"����շ�֧���ĳ����������

    CreateBiTree(root,A);//������������н���������
    pre = NULL;
    Inthread(root);

    q =InPre(root); /*�Ҹ�����ǰ�������������������ǰ��*/
    cout<<root->data<<"��ǰ��Ϊ"<<q->data<<endl;
    q =InNext(root); /*�Ҹ����ĺ�������������������ĺ���*/
    cout<<root->data<<"�ĺ��Ϊ"<<q->data<<endl;
};
