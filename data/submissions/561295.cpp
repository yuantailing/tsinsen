#include <iostream>
using namespace std;
float* Map(float* p[], int n) {
	float* q = new float[n];
	for (int i = 0; i < n; ++i)
		q[n - 1 - i] = *p[i];
	return q;
}
void Disp(float a[], int n)
{
	for (int i = 0; i < n; i++)
	cout << a[i] << " ";
	cout << endl;
}
void Disp(float* a[], int n)
{
	for (int i = 0; i < n; i++)
	cout << *a[i] << " ";
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	float* a = new float[n];
	for(int i = 0; i < n; i++)
	cin >> a[i];
	Disp(a, n);
	float** p = new float* [n];
	for (int i = 0; i < n; i++)
		p[i] = &a[i];
	Disp(p, n);
	float* const b = Map(p, n);
	Disp(b, n);
	return 0;
}