#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int n;
	string strline;
	int len;
	int alpha,ti,lastalpha;
	ifstream fin("C-large-practice.in");
	ofstream fout("C-large-practice.out",ios_base::app);
	fin>>n;
	for(int t=0;t<n;++t){
		if(!t){
			fin.ignore();
		}
		getline(fin,strline);
		len=strline.length();
		fout<<"Case #"<<t+1<<": ";
		for(int i=0;i<len;++i){
			if(' '==strline[i]){
				alpha=0;ti=1;
			}else{				
				if(strline[i]<'p'){
					alpha=2+(strline[i]-'a')/3;
					ti=(strline[i]-'a')%3+1;
				}else if(strline[i]<'t'){
					alpha=7;
					ti=(strline[i]-'p')+1;
				}else if(strline[i]<'w'){
					alpha=8;
					ti=ti=(strline[i]-'t')+1;
				}else{
					alpha=9;
					ti=ti=(strline[i]-'w')+1;
				}	
			}
			if(i && alpha==lastalpha){
				fout<<" ";
			}
			for(int j=0;j<ti;++j){
				fout<<alpha;
			}
			lastalpha=alpha;
		}
		fout<<endl;
	}
}
