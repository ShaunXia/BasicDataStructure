#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Simplify
{
public:
    Simplify();
    void txtin();
    void display(); 
    void fun23();
    void fun24();
    void fun25();
    void getw();
    int ishaves();
    int isinw(char in);

private:
    string iamw[100];
    string left[100];
    string right[100];
    string f24right[100];
    string f24left[100];
    int sflag[100];
    int scount;
    int wcount;
    int f24count;
    int righthavas;
};
Simplify::Simplify()
{
    wcount=0;
    scount=0;
    memset(sflag, 0, sizeof(sflag));
    righthavas=0;
    f24count=0;
}

void Simplify::txtin(){
    ifstream fin("step2.txt");
    string temp,vt;
    scount=0;
    int i,j,strlen,loc;

/////////讀入所有行，分拆-> 左右兩邊///////////////////////////////
    while(!fin.eof())
    {
        getline(fin,temp);
        strlen=temp.length();
        loc=0;
        for(i=0;i<strlen;++i)
        {
            if(temp[i]=='-')
            {
                i++;
                loc=1;
            }    
            else
            {
                if(loc==0)
                {
                    left[scount]+=temp[i];
                }
                if(loc==1)
                {
                    right[scount]+=temp[i];
                }
            }

        }
       scount++;
    }
    fin.close();
}

////////////分拆結束，分別存入 left、right數組///////////////
int Simplify::ishaves()
{
    int i,j;
    for(i=0;i<scount;++i)
    {
        for(j=0;j<right[i].length();++j)
        {
            if(right[i][j]=='S')
                {
                    righthavas=1;
                    return 1;
                }
        }
    }
    return 0;
}
void Simplify::getw()
{
    int i,j,k,l,tplen,flag;
    string tpstr;
    for(i=0;i<scount;++i)
    {
        flag=0;
        tpstr=right[i];
        tplen=tpstr.length();
        for(l=0;l<wcount;++l)
         {
            if(left[i]==iamw[l])
                {
                 flag=1;   
                }
         }
         if(flag==1)
            continue;
        for(j=0;j<tplen;++j)
        {
            if(tpstr[j]=='$'&&sflag[i]==0&&(left[i][0]!='S'||ishaves()))
            {
                iamw[wcount++]=left[i];
                sflag[i]=1;
                break;
            }
            for(k=0;k<wcount;++k)
            {
                if(tpstr[j]==iamw[k][0]&&sflag[i]==0&&(left[i][0]!='S'||ishaves()))
                {
                    iamw[wcount++]=left[i];
                    sflag[i]=1;
                    break;
                }
            }
        }    
                
    }
}

void Simplify::fun23()
{
    int i=0;
    while(1)
    {
        getw();
        if(i==wcount)
            break;
        else
            i=wcount;
    }
}
////////////////////////2.4 HERE//////////////////////////////
int Simplify::isinw(char in)
{
    for(int i=0;i<wcount;++i)
    {
        if(in==iamw[i][0])
            return 1;
    }
    return 0;
}

void Simplify::fun24()
{
    int i,j,k,tplen;
    string tp;
    for(i=0;i<scount;++i)
    {
        tp=right[i];
        tplen=tp.length();
        if(right[i][0]=='$')
            continue;
        f24left[f24count]=left[i];
        f24right[f24count++]=right[i];
        for(j=0;j<tplen;++j)
        {
            if(isinw(tp[j]))
               {
                    f24left[f24count]=left[i];
                    f24right[f24count++]=tp.substr(0,j)+tp.substr(j+1,tplen);
               }
        }
    }
    if(ishaves())
    {
        f24left[f24count]="S1";
        f24right[f24count++]="$";        
    }
}


void Simplify::fun25()
{
    int i,j,k;
    for(i=0;i<scount;++i)
    {
        if(left[i]=="S")
        {
            left[scount]="S1";
            right[scount++]=right[i];   
        }
    }
}

void Simplify::display()
{
    int i,tp;
    ofstream out("step2_empty.txt");
    for(i=0;i<f24count;++i)
        {
            cout<<f24left[i]<<"->"<<f24right[i]<<endl;
            out<<f24left[i]<<"->"<<f24right[i]<<endl;
        }
}
int main()
{
    int i,j,k;
    Simplify simple;
    simple.txtin();
    simple.fun23();
    if(simple.ishaves())
        
        {
            simple.fun25();
            simple.fun24();
        }
    else
        simple.fun24();
    simple.display();
    return 0;
}
