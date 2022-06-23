#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
#include<queue>
#include<stack>
#include<map> 
#include<string.h>
#define ll long long
#define inf 1e7
using namespace std;
ll a[200000];
map<ll, ll> mp;
int test_main()
{
	int t;
	scanf_s("%d", &t);
	while (t--)
	{
		mp.clear();
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i<n; i++)
		{
			scanf_s("%lld", &a[i]);
			mp[a[i]]++;
		}
		sort(a, a + n);
		ll minn = 2000000000;
		for (int i = n - 1; i >= 1; i--)
		{
			minn = min(minn, a[i] - a[i - 1]);
		}
		ll ans = 0;
		if (minn == 0)
			for (int i = n - 1; i >= 1; i--)
			{
				if (mp[a[i]]>1)
				{
					ll te = mp[a[i]];
					ans += te*(te - 1) / 2;
					mp[a[i]] = 1;
				}
			}
		else
			for (int i = n - 1; i >= 1; i--)
			{
				if (minn == a[i] - a[i - 1])
				{
					ans += mp[a[i]] * mp[a[i - 1]];
				}
			}
		printf("%lld %lld\n", minn, ans);
	}
	return 0;
}
// 2 5 1 2 5 4 3 4 3 3 3 10