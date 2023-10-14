

const int nanugi=1000000007;
const int MAX=2000000;
ll fac[MAX+5], fac_inv[MAX+5];

ll power(int n, int r){
  if(r==0) return 1;

  ll temp=power(n, r/2);
  temp=temp*temp%nanugi;

  if(r%2) temp=n*temp%nanugi;
  return temp;
}

void factorial_init(){
  int i;
  fac[0]=1;
  for(i=1; i<=MAX; i++){
    fac[i]=i*fac[i-1];
    fac[i]%=nanugi;
  }
  fac_inv[MAX]=power(fac[MAX], nanugi-2);
  for(i=MAX-1; i>=0; i--){
    fac_inv[i]=fac_inv[i+1]*(i+1)%nanugi;
  }
}

ll ncr(int n, int r){
  return fac[n]*fac_inv[n-r]%nanugi*fac_inv[r]%nanugi;
}

int main(){
  factorial_init();
}
