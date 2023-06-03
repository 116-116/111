#include<iostream>
#include<cmath>
using namespace std;
const int N=5e5+5,X=log2(N)+1;
int dep[N],st[N*2][30];
int head[N],ed[2*N],val[2*N],nex[2*N],idx;
int first[N],top;
//first  点i第一次出现的位置
void add(int a,int b,int c=1)
{
  ed[++idx]=b;
  val[idx]=c;
  nex[idx]=head[a];
  head[a]=idx;
}
void dfs(int rt,int fa)
{
  st[++top][0]=rt;//初始化st数组
  first[rt]=top;
  for(int i=head[rt];i;i=nex[i])
  {
    if(ed[i]==fa)continue;
    dep[ed[i]]=dep[rt]+1;
    dfs(ed[i],rt);
    st[++top][0]=rt;
  }
}
void GetSt()
{
  for(int j=1;(1<<j)<=top;++j)
  for(int i=1;i+(1<<j)-1<=top;++i)
  {
    int id1=st[i][j-1],id2=st[i+(1<<(j-1))][j-1];
    if(dep[id1]<dep[id2])st[i][j]=id1;
    else st[i][j]=id2;
  }
}
int RMQ(int x,int y)
{
  int d=log2(y-x+1);
  int id1=st[x][d],id2=st[y-(1<<d)+1][d];
  return dep[id1]<dep[id2]?id1:id2;
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
  dep[rt]=0;
  dfs(rt,0);
  GetSt();
  while(m--)
  {
    cin>>x>>y;
    if(first[x]>first[y])swap(x,y);
    cout<<RMQ(first[x],first[y])<<'\n';
  }
  return 0;
}