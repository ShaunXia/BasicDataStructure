#include <iostream>
#include <string>
using namespace std;
class VexNode
{
public:
    char Vertex;
    int Weight;
    VexNode *NextArc;
};
class Graph
{
public:
    int VertexNum;
    VexNode *AdjList;
};
class GFun
{public:
    int getVexNodeNo(Graph *g,char c);
    void InsertLinkList(Graph *g,char x,char y);
    void CreateGraph(Graph *g);
    void display(Graph *g);
    void BFS(Graph *g);
    int isinarr(char c);
private:
    int arrcount;
    char cc[1000];
};
int GFun::getVexNodeNo(Graph *g,char c)
{
    int j;
    for(j=0;j<g->VertexNum;++j)
    {
        if(g->AdjList[j].Vertex==c)
            return j;
    }
}
void GFun::InsertLinkList(Graph *g,char x,char y)
{
    int j;
    VexNode *p,*q;
    j=getVexNodeNo(g,x);
    //cout<<j<<endl;
    q=new VexNode;
    q->Vertex=y;
    q->NextArc=NULL;
    if((g->AdjList[j].NextArc==NULL)||(g->AdjList[j].NextArc->Vertex>y))
    {
        q->NextArc=g->AdjList[j].NextArc;
        g->AdjList[j].NextArc=q;
    }
    else
    {
        p=g->AdjList[j].NextArc;
        while(p->NextArc&&p->NextArc->Vertex<y)
            p=p->NextArc;
        q->NextArc=p->NextArc;
        p->NextArc=q;
    }
}
//hello 
void GFun::CreateGraph(Graph *g)
{
    int i,ArcNum;
    char x,y;
    cin>>g->VertexNum;
    g->AdjList=new VexNode[g->VertexNum+1];
    for(i=0;i<g->VertexNum;++i)
    {
        cin>>g->AdjList[i].Vertex;
        g->AdjList[i].NextArc=NULL;
    }
    cin>>ArcNum;
    for(i=0;i<ArcNum;++i)
    {
        cin>>x;
        cin>>y;
        InsertLinkList(g,x,y);
        //cout<<i<<endl;
        InsertLinkList(g,y,x);
    }
}

void GFun::display(Graph *g)
{
    int i;
    VexNode *p;
    for(i=0;i<g->VertexNum;++i)
    {
        cout<<g->AdjList[i].Vertex<<":";
        p=g->AdjList[i].NextArc;
        while(p)
        {
            cout<<"->"<<p->Vertex;
            p=p->NextArc;
        }
        cout<<"^"<<endl;
    }
}
void GFun::BFS(Graph *g)
{
    int visited[1000];
    int n,i,j;
    VexNode *p;
    //memset(visited,0,sizeof(visited));
    arrcount=0;
    for(i=0;i<g->VertexNum;++i)
    {
        n=getVexNodeNo(g,g->AdjList[i].Vertex);
        p=g->AdjList[i].NextArc;
        if(!isinarr(g->AdjList[i].Vertex))
        {
            cout<<g->AdjList[i].Vertex;
            if(arrcount<g->VertexNum)
                cout<<" ";
            cc[arrcount++]=g->AdjList[i].Vertex;
        }
        while(p)
        {
        if(!isinarr(p->Vertex))
            {
            cc[arrcount++]=p->Vertex;
            cout<<p->Vertex;
            if(arrcount<g->VertexNum)
                cout<<" ";
            }
            p=p->NextArc;
        }
    }
}
int GFun::isinarr(char c)
{
    for(int i=0;i<arrcount;++i)
    {
        if(cc[i]==c)
            return 1;
    }
    return 0;
}
int main()
{
    GFun gf;
    Graph *gp=new Graph();
    gf.CreateGraph(gp);
    //gf.display(gp);
    gf.BFS(gp);
    cout<<endl;
    system("pause");
}
