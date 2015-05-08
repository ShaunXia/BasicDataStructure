#include <iostream>
#include <string>
using namespace std;

void GetNext(const string &p,int next[])
{
    int j = 1,k = 0;
    next[0] = -1;
    next[1] = 0;
    while(j<p.length()-1)
    {
    if(p[j] == p[k])
    {
    next[j+1] = k+1;
    j++;
    k++;
    }
    else if(k == 0)
    {
    next[j+1] = 0;
    j++;
    }
    else k = next[k];
    }
}

int main()
{
    string sources="abacabadababc";
    string pattern="abaabcac";
                //覆盖数组  -1 -1 0 1
    int patlen=pattern.size();
    int soulen=sources.size();
    int next[8];
    GetNext(pattern,next);
    for(int i=0;i<patlen;++i)
        cout<<next[i]<<" ";
    system("pause");

    return 0;
}
