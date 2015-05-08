#include <iostream>
using namespace std;
char *vex;
int num;
int isempty(int n)
{
    if((2*n>num&&2*n+1>num)||(vex[2*n]=='0'&&vex[2*n+1]=='0'))
        return 0;
    if(vex[2*n]!='0'&&vex[2*n+1]!='0')
        return 3;
    if(vex[2*n]!='0')
        return 1;
    if(vex[2*n+1]!='0')
        return 2;
}
int main()
{

    int i,j;
    cin>>num;
    cin.get();
    vex=new char[num+1];
    for(i=1;i<=num;++i)
    {
        cin>>vex[i];
    }

    for(i=1;i<=num;++i)
    {
        if(isempty(i)==1)
    }
    return 0;
}
