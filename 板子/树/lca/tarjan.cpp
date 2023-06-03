#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
const int N=500000+5;
vector<int>E[N];
int idx,head[N],ed[N*2],val[N*2],nex[N*2];
int fa[N],dep[N],ans[N];
void add(int a,int b,int c)
{
    ed[++idx]=b;
    nex[idx]=head[a];
    val[idx]=c;
    head[a]=idx; 
}

void dfs(int rt,int fa)
{
  for(auto i:E[rt])
  {
    if(i==fa)continue; //防止往回走
    dep[i]=dep[rt]+1;//深度+1
    dfs(i,rt);
  }
}
int find(int x)//
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void lca_tarjan(int rt,int f)
{
  for(auto i:E[rt])
  {
    if(i==f)continue;
    lca_tarjan(i,rt);
    fa[find(i)]=rt;
  }
  for(int i=head[rt];i;i=nex[i])//看看所查点对包含rt的，是否有共同祖先，此时有的话就是最近的共同祖先
    if(fa[ed[i]]!=ed[i])ans[val[i]]=find(ed[i]);
}
int main()
{
  int m,n,rt;
    int a,b;
  cin>>n>>m>>rt;
  for(int i=1;i<=n;++i)fa[i]=i;
  for(int i=1;i<n;++i)
  {
    cin>>a>>b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  for(int i=1;i<=m;++i)
  {
    cin>>a>>b;
    if(a==b)ans[i]=a;
    add(a,b,i);
    add(b,a,i);
  }
  dep[rt]=0;
  dfs(rt,0);

  lca_tarjan(rt,0);
  for(int i=1;i<=m;++i)cout<<ans[i]<<endl;
  return 0;

}