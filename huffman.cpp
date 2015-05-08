#include <iostream>
#include <string>
using namespace std;
class HuffmanNode
{
public:
    int leftchild;
    int rightchild;
    int parent;
    int weight;
    int flag;
    char data;
};

class Huffman
{
public:
    Huffman(int n,int wt[],char cr[]);
    void makeTree(HuffmanNode *hufftree,int n);
    void doThat(int n);
    void codeing();
    void abc2huff(string st);
    void huff2abc(string st);
private:
    HuffmanNode *hufftree;
    int weight[1000];
    char usrchar[1000];
    string fina[1000];
    int ncount;
};

Huffman::Huffman(int n,int wt[],char  cr[])
{
    for(int i=0;i<n;++i)
    {
        weight[i]=wt[i];
        usrchar[i]=cr[i];     
    }
    ncount=n;
}
void Huffman::doThat(int n)
{
    hufftree=new HuffmanNode[2*n+1];
    makeTree(hufftree,n);
}

void Huffman::makeTree(HuffmanNode *hufftree,int n)
{
    int min1,min2,loc1,loc2,i,j,k;
    for(i=0;i<2*n+1;++i)
    {
        if(i<n)
            hufftree[i].weight=weight[i];
        else
            hufftree[i].weight=0;
        hufftree[i].parent=-1;
        hufftree[i].leftchild=-1;
        hufftree[i].rightchild=-1;
        hufftree[i].flag=0;
    }

    for(i=0;i<n-1;++i)
    {
        min1=min2=99999;
        loc1=loc2=0;
        for(j=0;j<n+i;++j)
        {
            if(hufftree[j].weight<min1&&hufftree[j].flag==0)
            {
                min1=hufftree[j].weight;
                loc1=j;
            }
        }
        hufftree[loc1].flag=1;
        for(j=0;j<n+i;++j)
        {
            if(hufftree[j].weight<min2&&hufftree[j].flag==0)
            {
                min2=hufftree[j].weight;
                loc2=j;
            }
        }
        hufftree[loc1].parent=n+i;
        hufftree[loc2].parent=n+i;
        hufftree[loc1].flag=1;
        hufftree[loc2].flag=1;
        hufftree[n+i].weight=hufftree[loc2].weight+hufftree[loc1].weight;
        hufftree[n+i].leftchild=loc1;
        hufftree[n+i].rightchild=loc2;

    }
}

void Huffman::codeing()
{
    int child,parent;
    string tp[1000];
    for(int i=0;i<ncount;++i)
    {
        child=i;
        parent=hufftree[child].parent;
        while(parent!=-1)
        {
            if(hufftree[parent].leftchild==child)
                tp[i]+="0";
            else
                tp[i]+="1";
            child=parent;
            parent=hufftree[child].parent;
        }
    }
    for(int i=0;i<ncount;++i)
    {
        int len=tp[i].length();
        while(len--)
        {
            fina[i]+=tp[i][len];
        }
    }
    for(int i=0;i<ncount;++i)
   {
    cout<<fina[i];
    if(i+1!=ncount)
        cout<<" ";
   }
   cout<<endl; 
}

void Huffman::abc2huff(string st)
{
    int len=st.length();
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<ncount;++j)
        {
            if(st[i]==usrchar[j])
            {
                cout<<fina[j];
                break;
            }
        }
    }
    cout<<endl;
}

void Huffman::huff2abc(string st)
{
    int len=st.length();
    int flag=0;
    int cutlen=0;
    string tp;
    for(int i=0;i<len;++i)
    {
        if(flag==0)
       
            tp+=st[i];
        else
        {
            tp=st[i];
            flag=0;
        }
        for(int j=0;j<ncount;++j)
        {
            if(tp==fina[j])
            {
                cout<<usrchar[j];
                flag=1;
            }
        }
    }
    cout<<endl;
}
int main()
{
    int i,j,k,ncount;
    int weight[1000];
    char usrchar[1000];
    cin>>ncount;
    for(i=0;i<ncount;++i)
    {
        cin>>usrchar[i];
    }
    for(i=0;i<ncount;++i)
    {
        cin>>weight[i];
    }
    string abc;
    string huff;
    Huffman huf(ncount,weight,usrchar);
    huf.doThat(ncount);
    huf.codeing();
    cin>>abc;
    huf.abc2huff(abc);
    cin>>huff;
    huf.huff2abc(huff);
    system("pause");
    return 0;
} 
