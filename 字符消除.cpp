#include <iostream>
#include <string>
using namespace std;

void process(string &str,int &ans)//字符串处理，消除重复
{
	char c=str[0];
	int beg=0,num=1;
	int index=0;
	int i=0;
	while(str.length()&&beg<str.length()-1){
		if(c==str[i+1]){
			++num;
		}else{
			if(num>1){		
				str.erase(beg,num);
				c=str[beg];
				i=beg;
				ans+=num;
				num=1;
				continue;
			}
			beg=i+1;
			c=str[i+1];
		}
		++i;
	}
}

void process2(string strOrg,int &ans)
{
	string str;
	str.assign(strOrg);
	int len=str.length();
	if(len==1){
		ans=2;
		return;
	}else{
		string in[3]={"A","B","C"};
		int initValue=ans;
		for(int i=0;i<=len;++i){
			for(int j=0;j<3;++j){
				str.assign(strOrg);
				int val=initValue;
				str.insert(i,in[j]);
				int re=initValue;
				process(str,val);
				while(re!=val){
					re=val;
					process(str,val);
				}
				if(val>ans){
					ans=val;
				}
			}
		}
	}
}

int main()
{
	int n;
	string str;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>str;
		int ans=0;
		process2(str,ans);
		cout<<ans<<endl;
	}
}
