// RMQ+LCA using Sparse Table
// Euler-Tour
// LCA for unrooted trees 
#include<bits/stdc++.h>

using namespace std;
vector<int> v[200005];
int level[200005];
int b[500005][20];
vector<int>lv;
int visited[200005];
vector<int>euler;
void dfs(int start)
{
	visited[start]=1;
	euler.push_back(start);
	for (int i = 0; i < v[start].size(); ++i)
	{
		int adj=v[start][i];
		if(visited[adj]==0)
		{
			level[adj]=level[start]+1;
			dfs(adj);
			euler.push_back(start);
		}
	}
}

int RMQ(int l,int r)
{
	if(l>r)
		swap(l,r);
	int len=log2(r-l+1);
	if(lv[b[l][len]]>lv[b[r-(int)pow(2,len)+1][len]])
		return b[r-(int)pow(2,len)+1][len];
	return b[l][len];

}

int lca(int u, int v)
{
	return euler[RMQ(visited[u],visited[v])]; 
}

void pre(int n)
{
		for (int i = 1; i <=n ; ++i)
		{
			b[i][0]=i;
		}
		//preprocess
		for (int j = 1; (1<<j) <=n ; j++)
		{
			for (int i = 1; i+(1<<j)-1 <=n ; ++i)
			{
				if(lv[b[i][j-1]]<lv[b[i+(1<<(j-1))][j-1]])
					b[i][j]=b[i][j-1];
				else
					b[i][j]=b[i+(1<<(j-1))][j-1];
			}
		}
}
int main()
{

		int n,num,x,q;
		cin>>n;
		level[1]=0;
		for (int i = 1; i <n ; ++i)
		{
			cin>>num>>x;
			v[num].push_back(x);
			v[x].push_back(num);
		}
		euler.push_back(0);
		lv.push_back(0);
		dfs(1);
		memset(visited,0,sizeof(visited));
		for (int i = 1; i <euler.size() ; ++i)
		{
			if(visited[euler[i]]==0)
			visited[euler[i]]=i;
			lv.push_back(level[euler[i]]);
		}
		pre(lv.size());
		cin>>q;
		int g,h,r;
		for (int i = 0; i < q; ++i)
		{
			cin>>r>>g>>h;
			int res1=lca(r,g);
			int res2=lca(g,h);
			int res3=lca(r,h);
			if(res1==res2&&res1==res3)
				cout<<res1<<endl;
			else
			{
				if(res1==res2)
					cout<<res3<<endl;
				else if(res1==res3)
					cout<<res2<<endl;
				else
					cout<<res1<<endl;
			}
		}
	return 0;
}
