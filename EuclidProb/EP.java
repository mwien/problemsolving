import java.util.Scanner;

public class EP {

    public static long[] EEA(long a, long b) {
	if(b == 0) {
	    long[] A = {a, 1, 0};
	    return A;
	}
	long[] B = EEA(b, a % b);
	long[] C = new long[3];
	C[0] = B[0];
	C[1] = B[2];
	C[2] = B[1] - (a / b) * B[2];
	return C;
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	while(s.hasNext()) {
	    long a = s.nextLong();
	    long b = s.nextLong();
	    long[] C = EEA(a, b);
	    long D = C[0];
	    long X = C[1] % (b/D);
	    long Y = C[2] + X - C[1];
	    long X2 = X - b/D;
	    long Y2 = Y + a/D;
	    
	     if(Math.abs(X2) + Math.abs(Y2) < Math.abs(X) + Math.abs(Y) || (Math.abs(X2) + Math.abs(Y2) == Math.abs(X) + Math.abs(Y) && X2 <= Y2)) {
		X = X2;
		Y = Y2;
	    }
	    System.out.println(X + " " + Y + " " + D);
	}
    }

}