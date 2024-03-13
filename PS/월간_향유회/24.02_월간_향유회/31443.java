import java.util.Scanner;
/*
import java.util.Arrays;
import java.util.Collections;
import java.lang.Math;
*/
public class Main {
	static long nanugi=1000000007;

    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);

    	long n, m, ans=0;
    	n=in.nextLong();
    	m=in.nextLong();
    	if(m%3==2) {
    		long temp=n;
    		n=m;
    		m=temp;
    	}
    	if(n%3==0 || m%3==0) ans=power(3, n*m/3);
    	else if(n==1 && m==1) ans=1;
    	else if(n%3==2) {
    		ans=power(3, (n-2)*m/3)*power(3, 2*(m/3))%nanugi;
    		ans=ans*(m%3*2)%nanugi;
    	}
    	else if (n%3==1) {
    		ans=power(3, (n*m-1)/3-1)*4%nanugi;
    	}

    	System.out.println(ans);
    	in.close();
    }

    static long power(long n, long k) {
    	if(k==0) return 1;
    	else if(k%2==1) return power(n, k-1)*n%nanugi;
    	else {
    		long tmp=power(n, k/2);
    		return tmp*tmp%nanugi;
    	}
    }
}
