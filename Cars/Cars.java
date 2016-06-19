import java.util.Scanner;

public class Cars {
    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	while(true) {
	    int n = s.nextInt();
	    if(n == 0) break;
	    int[] a = new int[n+1];
	    for(int i = 1; i < n+1; i++) {
		a[i] = s.nextInt();
	    }
	    double b = s.nextDouble();
	    int r = s.nextInt();
	    double v = s.nextDouble();
	    double e = s.nextDouble();
	    double f = s.nextDouble();
	    double[] tpd = new double[a[n]+1];
	    for(int i = 0; i < tpd.length; i++) {
		if(i == 0) tpd[i] = 0;
		else {
		    double time;
		    if((i-1) >= r) {
			time = 1 / (v - e * ((i-1) - r));
		    } else {
			time = 1 / (v - f * (r - (i-1)));
		    }
		    tpd[i] = tpd[i-1] + time;
		}
	    }
	    double[] T = new double[n+1];
	    for(int i = 0; i < n+1; i++) {
		if(i == 0) {
		    T[i] = 0;
		    continue;
		}
		double min = Double.MAX_VALUE;
		for(int j = 0; j < i; j++) {
		    double val = T[j] + tpd[a[i] - a[j]];
		    if(val < min) min = val;
		}
		T[i] = min + b;
	    }
	    double min = Double.MAX_VALUE;
	    for(int i = 0; i < n; i++) {
		double val = T[i] + tpd[a[n] - a[i]];
		if(val < min) min = val;
	    }
	    System.out.printf("%.4f\n", min);
	}
    }
}