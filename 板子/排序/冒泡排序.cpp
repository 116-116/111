void bubble_Sort(int *a,int n)
{
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=n-i;++j)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
    }
}//复杂度O(n^2)