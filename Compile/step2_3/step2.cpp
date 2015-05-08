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
    void getW();
    void getP1();
    int inCW(char c);

private:
    string left[100];
    string right[100];
    string w[100][100];
    string pleft[100];
    string pright[100];
    char cw[100];
    int ewcount[100];
    int scount;
    int pcount;
    int cwcount;
};
Simplify::Simplify()
{
    scount=0;
    cwcount=0;
    memset(ewcount,0,sizeof(ewcount));
    pcount=0;
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

int Simplify::inCW(char c)
{
    int i,j;
    for(i=0;i<cwcount;++i)
    {
        if(c==cw[i])
            {
                return i;
            }
        
    }
    return -1;
}

void Simplify::getW()
{
    int i,j,k,tplen,n;
    string tp;
    for(i=0;i<scount;++i)
    {
        int addto=1;
        tp=right[i];
        tplen=tp.length();
        n=inCW(left[i][0]);

        if(n==-1)
        {
            cw[cwcount]=left[i][0];
            n=cwcount++;
        }
        //int rin=0;            
        if(ewcount[n]==0)
                {
                    w[n][ewcount[n]++]=cw[n];
                }
        for(j=0;j<tplen;++j)
        {

            addto=1;
            if(tp[j]>=65&&tp[j]<=90)
                {
                    for(k=0;k<ewcount[n];++k)
                    {
                        if(w[n][k][0]==tp[j])
                            {
                                addto=0;
                                break;
                            }
                    }

                    if(addto==1)
                    {
                        w[n][ewcount[n]++]=tp[j];
                    }
                }
        }

    }
}

void Simplify::getP1()
{
    int i,j,k;
    for(i=0;i<cwcount;++i)
    {
        for(j=0;j<ewcount[i];++j)
        {
            for(k=0;k<scount;++k)
            {
                if(left[k]==w[i][j]&&(right[k].length()>1||right[k][0]>90))
                    {
                        pleft[pcount]=cw[i];
                        pright[pcount++]=right[k];
                    }
            }
        }
    }
}

void Simplify::display()
{
    int i,j,tp;
    ofstream out("step2_for2.2.txt");
    for(i=0;i<pcount;++i)
    {
        cout<<pleft[i]<<"->"<<pright[i]<<endl;
        out<<pleft[i]<<"->"<<pright[i]<<endl;
    }
    cout<<"FUNCTION 2.6 FINISHED. CALL FUNCTION 2.2 TO DELETE USELESS SYMBOL"<<endl;
    system("step2_2.2.exe");
    cout<<"step2_for2.2.txt OUTPUT FOR 2.2"<<endl;
    cout<<"step2_2.6_FINAL.txt IS THE FINAL RESULT "<<endl;
    out.close();
}

int main()
{
    int i,j,k;
    Simplify simple;
    simple.txtin();
    simple.getW();
    simple.getP1();
    simple.display();
    system("pause");
    return 0;
}
