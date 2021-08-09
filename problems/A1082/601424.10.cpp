int findKth(int *s, int n, int K)
{
	int p=n/2;
	int l=0;
	int r=n-1;
	int t;
	int sp=s[p];
	do
	{
		while (s[l]<sp) l++;
		while (s[r]>sp) r--;
		t=s[r];
		s[r]=s[l];
		s[l]=t;
	}while (l<r);
	if (p==K-1) return s[p];
	else if (p<K-1) return findKth(s+p,n-p,K-p);
	else return findKth(s,n-p,K);
}
