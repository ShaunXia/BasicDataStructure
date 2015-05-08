#include <iostream>
#include <string>
using namespace std;
 
class String
{
private:
    string mainstr;
    int size;
    void GetNext(const string &p,int next[]);
    int KMPFind(const string &p,int pos,int next[]);
 
public:
    String();
    ~String();
    void SetVal(const string &sp);
    int KMPFindSubstr(const string &p,int pos);
 
};
String::String()
{
    size = 0;
    mainstr = "";
}
String::~String()
{
    size = 0;
    mainstr = "";
}
 
void String::SetVal(const string &sp)
 
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
 
void String::GetNext(const string &p,int next[])
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
 
 
int String::KMPFind(const string& p,int pos,int next[])
{
    int i = pos, j = 0,v;
    int L = p.length();
    while((i<size) && (j<L))
    {
        if(j == -1 || mainstr[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j == p.length())
        v = i-p.length();
    else
        v = -1;
    return v;
 
}
 
int String::KMPFindSubstr(const string& p,int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p,next);
    for (i = 0;i<L;i++)
        cout<<next[i]<<' ';
    cout<<endl;
    int v = -1;
    v = KMPFind(p,pos,next);
 
    delete []next;
    return v;
}
 
int main()
{
    int t,i,pos;
    string s1,p1;
    cin>>t;
    for(i = 0;i<t;i++)
    {
        pos = 0;
        cin>>s1;
        cin>>p1;
        String ms;
        ms.SetVal(s1);
        pos = ms.KMPFindSubstr(p1, 0)+1;
        cout<<pos<<endl;
    }
    return 0;
}