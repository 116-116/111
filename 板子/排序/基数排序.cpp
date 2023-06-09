const int N = 10;
const int W = 10;
const int K = 100;

int n, w[K], k, cnt[W];//k为最大位数，w为每个位的值域。
int x[N];
struct Element
{
  int key[K];

  bool operator<(const Element &y) const
  {
    // 两个元素的比较流程
    for (int i = 1; i <= k; ++i)
    {
      if (key[i] == y.key[i])
        continue;
      return key[i] < y.key[i];
    }
    return false;
  }
} a[N], b[N];

void counting_sort(int p)
{
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i)
    ++cnt[a[i].key[p]];
  for (int i = 1; i <= w[p]; ++i)
    cnt[i] += cnt[i - 1];
  // 为保证排序的稳定性，此处循环i应从n到1
  // 即当两元素关键字的值相同时，原先排在后面的元素在排序后仍应排在后面
  for (int i = n; i >= 1; --i)
    b[cnt[a[i].key[p]]--] = a[i];
  // memcpy(a, b, sizeof(a));
}

void radix_sort()
{
   for (int i = k; i >= 1; --i)
  {
    // 借助计数排序完成对关键字的排序
    counting_sort(i);
  }
}
//时间复杂度 O(kn+kw) 空间复杂度 O(k+n);