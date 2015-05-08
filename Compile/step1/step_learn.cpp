#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int deletestar=0; //delete star flag *
string deleteit(string str)
{
	int deleteflag=1;
	int len=str.length();
	string finstr="";
	string tp;
	int i;
	if(deletestar==1)
	{
		for(i=0;i<len;++i)
		{
			if(str[i]=='*'&&str[i+1]=='/'&&deletestar==1){
				deletestar=0;
				return str.substr(i+2,len-i-2);
			}
		}
		if(deletestar==1)
			return "~~";
	}
	//delete "//" line & scan  " /* "
	for(i=0;i<len;++i){

		if(str[i]=='\"'&&deleteflag==1)
			deleteflag=0;
		else
			if(str[i]=='\"'&&deleteflag==0)
				deleteflag=1;

		if((str[i]=='/')&&(str[i+1]=='/')&&deleteflag==1)
		{
			break;
		}
		else
		{
			if(str[i]=='/'&&str[i+1]=='*'&&deleteflag==1)
				{
					deletestar=1;
					return "~~";
				}
			else
				finstr+=str[i];
		}
	}
	return finstr;
}
int main()
{
	ifstream fin("step1.cpp");
	ofstream out("step1_fin.cpp");
	string str; 
	while(!fin.eof())
	{
		getline(fin,str);
		string stp;
		stp=deleteit(str);
		if(stp!="~~"&&stp!=""&&stp!="	") 
			out<<stp<<endl;
	}
	return 0;
}
