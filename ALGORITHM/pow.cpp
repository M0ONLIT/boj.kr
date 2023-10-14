typedef long long ll;
const int nanugi=1000000007;

ll power(int n, int r){
  if(r==0) return 1;

  ll temp=power(n, r/2);
  temp=temp*temp%nanugi;

  if(r%2) temp=n*temp%nanugi;
  return temp;
}
