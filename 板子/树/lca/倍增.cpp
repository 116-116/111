#include<iostream>
#include<cmath>
using namespace std;
const int N=5e5+5,X=log2(N)+1;
int dep[N],up[N][X];
int head[N],ed[2*N],val[2*N],nex[2*N],idx;
void add(int a,int b,int c=1)
{
  ed[++idx]=b;
  val[idx]=c;
  nex[idx]=head[a];
  head[a]=idx;
}
void dfs(int rt,int fa)
{
  up[rt][0]=fa;
  for(int i=1;i<X;++i)
    up[rt][i]=up[up[rt][i-1]][i-1];
  for(int i=head[rt];i;i=nex[i])
  {
    if(ed[i]==fa)continue;
    dep[ed[i]]=dep[rt]+1;
    dfs(ed[i],rt);
  }
}
void Up(int &u,int dist)
{
  for(int i=0;i<X;++i)
  {
    if((1<<i)&dist)
      u=up[u][i];
  }
}
int lca(int &x,int &y)
{
  if(dep[x]>dep[y])swap(x,y);
  Up(y,dep[y]-dep[x]);
  if(x==y)return x;
  int t=log2(dep[x]);
  for(int i=t;i>=0;--i)
  {
    if(up[x][i]!=up[y][i])
    {
      x=up[x][i],y=up[y][i];
    }
  }
  return up[x][0];
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m,x,y,rt;
  cin>>n>>m>>rt;
  for(int i=1;i<n;++i)
  {
    cin>>x>>y;
    add(x,y);
    add(y,x);
  }
  dep[1]=0;
  dfs(rt,0);
  // for(int i=1;i<=n;++i)cout<<dep[i]<<endl;
  while(m--)
  {
    cin>>x>>y;
    cout<<lca(x,y)<<'\n';
  }
  return 0;
}