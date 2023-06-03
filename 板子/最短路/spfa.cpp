int spfa()
{
	queue<int> q; 
    for(int i=1; i<=n; i++) //将所有结点入队
	{
	    st[i] = true;
		q.push(i);	  
    }
	while(q.size()) // 队列不空
	{
	   int t = q.front(); //取队头 
	   q.pop();
	   st[t] = false; // 代表这个点已经不在队列了
	   
	   for(int i = h[t]; i!=-1; i=ne[i]) // 更新 t 的所有临边结点的最短路 
	   {
	   	 int j = e[i];
	   	 if(dist[j] > dist[t]+w[i])
	   	 {
	   	    dist[j] = dist[t] + w[i];
	   	    cnt[j] = cnt[t] + 1; // t到起点的边数+1 
	   	    
	   	    if(cnt[j] >= n) return true;// 存在负环 
			if(!st[j])  //如果 j 不在队列，让 j 入队 
			{
				q.push(j); 
				st[j] = true;  // 标记 j 在队中 
			} 	    	
		 }
	   }	
	} 
	 return false;// 不存在负环 
}
//一般 O(m),最坏O(n);