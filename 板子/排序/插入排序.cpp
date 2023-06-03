void insert_Sort(int *a,int n)
{
    for(int i=2;i<=n;++i)
    {
        int k=a[i],j=i-1;
        while(j&&a[j]>k)a[j+1]=a[j],--j;
        a[j+1]=k;
    }
}//复杂度O(n^2)