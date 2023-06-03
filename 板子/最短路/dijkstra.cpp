//不能有负边
//朴素板 O(n^2)
const int N =2022, M =2022;
int g[N][N];
int vis[N], dist[N],n,m;
void init()
{
  memset(g,0x3f,sizeof g);
  fr(i,1,n)g[i][i]=0;
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
}
void dijkstra(int start)
{
  dist[start] = 0;
  fr(i,1,n-1)
  {
    int pos=0;
    fr(j,1,n)if(!vis[j]&&(!pos||dist[j]<dist[pos]))pos=j;
    vis[pos]=1;
    fr(j,1,n)dist[j]=min(dist[j],dist[pos]+g[pos][j]);
  }
}
//堆优化版 O(mlogn)
const int N =2022, M =200202;
int ed[2*M],val[2*M],nex[2*M];
int head[N],idx;
int dist[N];
bool vis[N];
void init()
{
  memset(dist,0x3f,sizeof dist);
  memset(vis,0,sizeof vis);
  memset(head,0,sizeof head);
}
void add(const int &a, const int &b, const int &c = 1)
{
  ed[++idx] = b;
  nex[idx] = head[a];
  val[idx] = c;
  head[a] = idx;
}
template<class T>
void dijkstra(int start)
{
  dist[start]=0;
  priority_queue<T,vector<T>,greater<T>>heap;
  heap.push({0,start});//{距离，点}
  while(heap.size())
  {
    T t=heap.top();
    heap.pop();
    if(vis[t.second])continue;
    vis[t.second]=1;
    for(int i=head[t.second];i;i=nex[i])
    {
      int j=ed[i];
      if(dist[j]>t.first+val[i])dist[j]=t.first+val[i],heap.push({dist[j],j});
    }
  }
}