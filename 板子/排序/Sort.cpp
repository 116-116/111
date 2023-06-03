template <class T>
class Sort
{
public:
  void m_HeapSort(T &a, int siz)
  {
    int t = siz / 2;
    while (t--)
      m_PushDown(a, t + 1, siz);
    while (siz)
    {
      swap(a[1], a[siz]);
      m_PushDown(a, 1, --siz);
    }
  }
  void m_QuickSort(T &p, int l, int r)
  {
    if (l >= r)
      return;
    int i = l - 1, j = r + 1, x = p[l + r >> 1];
    while (i < j)
    {
      do
        i++;
      while (p[i] < x);
      do
        j--;
      while (p[j] > x);
      if (i < j)
        swap(p[i], p[j]);
    }
    m_QuickSort(p, l, j), m_QuickSort(p, j + 1, r);
  }
  void m_MergeSort(T &p, int l, int r)
  {
    if (l == r)
      return;
    int mid = l + r >> 1;
    m_MergeSort(p, l, mid), m_MergeSort(p, mid + 1, r);
    T q;
    int L = l, R = mid + 1;
    while (L <= mid && R <= r)
    {
      if (p[L] < p[R])
        q.push_back(p[L++]);
      else
        q.push_back(p[R++]), m_Cnt += (mid - L + 1);
    }
    if (L > mid)
      while (R <= r)
        q.push_back(p[R++]);
    if (R > r)
      while (L <= mid)
        q.push_back(p[L++]);
    for (auto i : q)
      p[l++] = i;
  }
  int m_Cnt = 0; // 逆序对数量
private:
  void m_PushDown(T &a, int fa, int end)
  {
    int lr = fa << 1;
    while (lr <= end)
    {
      if (lr + 1 <= end && a[lr] < a[lr + 1])
        ++lr;
      if (a[fa] >= a[lr])
        return;
      swap(a[fa], a[lr]);
      fa = lr;
      lr = fa << 1;
    }
  }
};