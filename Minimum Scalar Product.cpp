#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define LL long long 
bool compare(LL a,LL b)
{
	return a<b;
}

int main()
{
	LL n;
	LL m;
	LL *v1,*v2;
	ifstream fin("A-large-practice.in");
	ofstream fout("A-large-practice.out",ios_base::app);
	fin>>n;
	for(LL t=0;t<n;++t){
		fin>>m;
		v1=new LL[m];
		v2=new LL[m];
		for(LL i=0;i<m;++i){
			fin>>v1[i];
		}
		for(LL i=0;i<m;++i){
			fin>>v2[i];
		}
		sort(v1,v1+m,compare);
		sort(v2,v2+m,compare);
		LL sum=0;
		for(LL i=0;i<m;++i){
			sum+=v1[i]*v2[m-i-1];
		}
		fout<<"Case #"<<t+1<<": "<<sum<<endl;
		delete[]v1;
		delete[]v2;
	}

}
