void Floyd(){
	for(int k = 1;k <= n; ++k)
		for(int i = 1;i <= n; ++i)
			for(int j = 1;j <= n; ++j)
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
}
on3