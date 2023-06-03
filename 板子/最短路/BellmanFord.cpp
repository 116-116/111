int bellman_ford()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1] = 0;
	
	for(int i=0; i<k; i++) 
	{
		memcpy(backup,dist,sizeof(dist)); //备份
		for(int j=0; j<m; j++)   // 枚举所有边 
		{
		   int a = edge[j].a, b = edge[j].b, w=edge[j].w;	
		   dist[b] = min(dist[b],backup[a]+w); // 用备份更新 
		}
	}
	if(dist[n] > 0x3f3f3f3f/2) return -1;
	return dist[n];
}
//有变数限制的最短路，最多k条边
// O(nm); 可以有负边
