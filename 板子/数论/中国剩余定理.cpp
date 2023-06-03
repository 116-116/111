#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll exgcd(ll a, ll b, int &x, int &y)
{
  if (b == 0)
  {
    x = a, y = 0;
    return a;
  }
  ll t = exgcd(b, a % b, x, y), z = x;
  x = y;
  y = z - a / b * y;
  return t;
}
ll crt(vector<ll> &m, vector<ll> &c)//m 方程组的模数，两两互质，n 余数
{
  ll M = 1, ans = 0;
  int x, y;
  for (int i = 0; i < m.size(); ++i)
    M *= m[i];
  for (int i = 0; i < m.size(); ++i)
  {
    exgcd(M / m[i], m[i], x, y);
    ans = (ans + c[i] * M / m[i] % M * x % M) % M;
  }
  return (ans % M + M) % M;
}
int main()
{
  ll p, e, x, d,t=0;
  vector<ll> m, c;
  m.push_back(23);
  m.push_back(28);
  m.push_back(33);
  while (cin >> p >> e >> x >> d)
  {
    c.clear();
    if(p==-1&&e==-1&&x==-1&&d==-1)break;
    c.push_back(p);
    c.push_back(e);
    c.push_back(x);
    ll ans=crt(m,c);
    if(ans<=d)ans=ans-d+21252;
    else ans=ans-d;
    cout<<"case" <<++t<<": the next triple peak occurs in ";
    cout << ans <<" days.\n";
  }
  return 0;
}