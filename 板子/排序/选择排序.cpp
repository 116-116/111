void select_Sort(int *a,int n)
{
    for(int i=1;i<=n;++i)
    {
        int k=i;
        for(int j=i+1;j<=n;++j)
            if(a[k]>a[j])k=j;
        swap(a[k],a[i]);
    }
}//复杂度O(n^2)