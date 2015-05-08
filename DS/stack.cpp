#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main( )
{
int n;
char item;
stack<char> numbers;
string st;
cin >> n;
item=cin.get();
int j;
for (int i = 0; i < n; i++) {
    cin>>st;
    int stlen=st.length();
    j=0;
    while(stlen--)
    {
        if(st[j]=='('||st[j]=='['||st[j]=='{')
            numbers.push(st[j]);
        else
        {
            if(st[j]==')')
                if(numbers.top()=='(')
                    numbers.pop();
                else
                {
                    cout<<"error"<<endl;
                    break;
                }
            if(st[j]==']')
                if(numbers.top()=='[')
                    numbers.pop();
                else
                {
                    cout<<"error"<<endl;
                    break;
                }
                if(st[j]=='}')
                if(numbers.top()=='{')
                    numbers.pop();
                else
                {
                    cout<<"error"<<endl;
                    break;
                }
        }
        ++j;
    }
    if(numbers.empty())
        cout<<"ok"<<endl;
    else
        cout<<"error"<<endl;
    //cout<<endl;
}
//system("pause");
}
