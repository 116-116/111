int a[N],b[N],cnt[N],n,w; //w 为a[i]的最大值。
void count_Sort()
{
    for(int i=1;i<=n;++i)++cnt[a[i]];
    for(int i=1;i<=w;++i)cnt[i]+=cnt[i-1];
    for(int i=n;i;--i)b[cnt[a[i]]--]=a[i];
    for(int i=1;i<=n;++i)a[i]=b[i];
}
//复杂度O(n+w)