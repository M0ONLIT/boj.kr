long long O[1000005]={0};
long long F[1000005]={0};
long long nanugi=1e9+7;

long long f(long long);

long long o(long long n){
	if (n==0) return 1;
	if(n<0) return 0;
	if(O[n]) return O[n];
	else{
		O[n]=(2*o(n-1)+o(n-2)+2*f(n-2))%nanugi;
	    return O[n];
	}
}

long long f(long long n){
	if (n==0) return 1;
	if(n<0) return 0;
	if(F[n]) return F[n];
	else{
		F[n]=(o(n)+f(n-1))%nanugi;
		return F[n];
	}
}
main(){
	long long n;
	scanf("%d",&n);
	printf("%d",o(n));
}
