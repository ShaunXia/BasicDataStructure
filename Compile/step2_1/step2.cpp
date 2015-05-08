#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Simplify
{
public:
    Simplify();
    void txtin();
    void putInVt1();
    void putInVt2();
    void putInP();
    void putinFin();
    void show();
    int getCount();
    int getVncount();
    int isInVn(char c);
    int isInVnVt(string c);
private:
    string left[100];
    string right[100];
    string vn[100];
    string pleft[100];
    string pright[100];
    string finleft[100];
    string finright[100];
    int fincount;
    int count;
    int vncount;
    int pcount;
};
Simplify::Simplify()
{
    vncount=0;   
    pcount=0; 
    fincount=1;
}
int Simplify::isInVn(char c)
{
    int i,j,slen;
    string tp;
    for(i=0;i<vncount;++i)
    {
        tp=vn[i];
        slen=tp.length();
        if(c==tp[0])
            return 1;
    }
    return 0;
}
void Simplify::txtin(){
    ifstream fin("step2.txt");
    string temp,vt;
    count=0;
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
                    left[count]+=temp[i];
                }
                if(loc==1)
                {
                    right[count]+=temp[i];
                }
            }

        }
       count++;
    }
    fin.close();

}
////////////分拆結束，分別存入 left、right數組///////////////

////////////判斷右側是否屬於Vt*，並加入左側加入Vn///判断右侧为终结符//////////
void Simplify::putInVt1(){
    
    int i,j;
    string temp;
    int slen;
    int flag;
    for(i=0;i<count;++i)
    {

        flag=1;
        temp=right[i];
        slen=temp.length();
        for(j=0;j<slen;++j)
        {
            int tp=temp[j];
            if(tp>=97&&tp<=122) //A 65 Z 90 a 97 z 122
                {
                    flag=1;   
                }
                else
                {
                    flag=0;
                    break;
                }
        }
        if(flag==1)
            vn[vncount++]=left[i];
    }

}
//////////////////////右侧终结符放入VN结束////////////////////////////////////////


/////////////////////算法2.1 第二步 循环右侧含有找出非终结符的产生式//////////
void Simplify::putInVt2()
{
    int i,j;
    string temp;
    int slen;
    int flag;
    for(i=0;i<count;++i)
    {

        flag=1;
        temp=right[i];
        slen=temp.length();
        for(j=0;j<slen;++j)
        {
            int tp=temp[j];
            if(tp>=97&&tp<=122) //A 65 Z 90 a 97 z 122
                {
                    flag=1;
                }
                else
                {
                    if(isInVn(tp))
                        flag=1;
                    else
                    {
                        flag=0;
                        break;   
                    }
                }
        }
        temp=left[i];
        int isexist=0,k;
        if(flag==1)
        {
            for(k=0;k<vncount;++k)
            {
                if(vn[k]==temp)
                {
                   isexist=1;
                    break;
                }
            }
            if(isexist==0)
                vn[vncount++]=temp;

        }
            
    }
}
/////////////END 算法2.1 第二步/////////////
int Simplify::isInVnVt(string c)
{
    int len=c.length();
    int i,j,k,flag=0;
    for(j=0;j<len;++j)
    {
        if(c[j]>=97&&c[j]<=122)
                {
                    flag=1;
                    continue;
                }
        for(i=0;i<vncount;++i)
        {
            if(c[j]==vn[i][0])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0)
            return 0;
    }
    return 1;
}

/////////////////////PUT INTO P///////////////////
void Simplify::putInP()
{
    int i,j,k,slen;
    string temp;
    for(i=0;i<count;++i)
    {
        //cout<<isInVnVt("W")<<endl;
        if(isInVnVt(right[i])&&isInVnVt(left[i]))
        {
            pleft[pcount]=left[i];
            pright[pcount++]=right[i];
        }
    }
}


/////////////////////算法2.1 结束///////////////////

void Simplify::putinFin()
{
    int i,j,k,now;
    string tp;
    finleft[0]=pleft[0];
    finright[0]=pright[0];
    //fincount++;
    int coin,jump;
    for(i=1;i<pcount;++i)
    {
        jump=0;
        coin=0;
        for(j=0;j<fincount;++j)
        {
            if(pleft[i]==finleft[j]&&pright[i]==finright[j])
                jump=1;
        }
        if(jump==1)
            continue;
        for(j=0;j<fincount;++j)
        {
            int slen=finright[j].length();
            for(k=0;k<slen;++k)
            {
                if(pleft[i][0]==finright[j][k]||pleft[i][0]=='S')
                {
                    finright[fincount]=pright[i];
                    finleft[fincount]=pleft[i];
                    coin=1;
                }
            }
        }
        if(coin==1)
            fincount++;
    }
}


void Simplify::show()
{
    ofstream out("step2_useless.txt");
    for(int i=0;i<fincount;i++)
    {
        cout<<finleft[i]<<"->"<<finright[i];
        cout<<endl;
        out<<finleft[i]<<"->"<<finright[i];
        out<<endl;
    }
    out.close();
}
int Simplify::getVncount()
{
    return vncount;
}
int Simplify::getCount()
{
    return count;
}

int main()
{
    Simplify simple;
    simple.txtin();
    simple.putInVt1();
    int vncount=0;
    int vncountfin=simple.getVncount();
    while(vncount<vncountfin)
    {
        simple.putInVt2();
        vncount=vncountfin;
        vncountfin=simple.getVncount();
    }

    simple.putInP();
    simple.putinFin(); 
    simple.putinFin();
    simple.show();
   

//////////////////////////////////////////////////////////////
    return 0;
}
