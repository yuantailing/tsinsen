#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 

using namespace std; 
const int N = 200010; 
int ml[N], mr[N], w[N], v[N]; 
long long tv[N], ts[N]; 
int main() 
{ 
    int n, m; 
    long long s, minn, k; 
    minn = 0xffffffffffffffLL; 
    cin >> n >> m >> s; 
    int maxn = 0; 
    for (int i = 1; i <= n; i++) 
    { 
        scanf("%d%d", &w[i], &v[i]); 
        if (w[i] > maxn) maxn = w[i]; 
    } 

    for (int i = 1; i <= m; i++) scanf("%d%d", &ml[i], &mr[i]); 
    int l = 1, r = maxn; 
    while (l <= r) 
    { 
        int mid=(l + r) / 2; 
        memset(tv, 0, sizeof(tv)); 
        memset(ts, 0, sizeof(ts)); 
        for (int i = 1; i <= n; i++) 
        { 
            tv[i] = tv[i - 1]; 
            ts[i] = ts[i - 1]; 
            if (w[i] > mid) 
            { 
                tv[i] += v[i]; 
                ts[i]++; 
            } 
        } 
        k = 0; 
        for (int i = 1; i <= m; i++) 
            k += (tv[mr[i]] - tv[ml[i] - 1]) * (ts[mr[i]] - ts[ml[i] - 1]); 
        if (k == s) {printf("0\n"); return 0;} 
        if (k < s) r = mid - 1; else l = mid + 1; 
        if (s - k >= 0 && s - k < minn) minn = s - k; 
           else if (k - s >= 0 && k - s < minn) minn = k - s; 
    } 
    cout<<minn<<endl; 
    return 0; 
}