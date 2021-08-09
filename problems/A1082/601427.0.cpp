int findKth(int *s, int n, int K)
{
	int*ss=new int[n];
	int top=-1,tail=n;
	int p=s[0];
	for (int i=0;i<n;i++)
		if (s[i]<p) ss[++top]=s[i];
		else if (s[i]>p) ss[--tail]=s[i];
	for (int i=top+1;i<tail;i++)
		ss[i]=p;
	memcpy(s,ss,n*sizeof(int));
	delete[]ss;
	if (K<=top+1) return findKth(s,top+1,K);
	else if (K>=tail+1) return findKth(s+tail,n-tail,K-tail);
	else return p;
}
