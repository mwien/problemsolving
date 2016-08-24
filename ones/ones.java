import java.math.BigInteger;
import java.util.Scanner;

public class ones {

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	while(s.hasNext()) {
	    int n = s.nextInt();
	    BigInteger N = new BigInteger(Integer.toString(n));
	    BigInteger test = BigInteger.ONE;
	    int cnt = 1;
	    while(true) {
		if(test.mod(N).equals(BigInteger.ZERO)) {
		    System.out.println(cnt);
		    break;
		}
		++cnt;
		test = test.multiply(BigInteger.TEN).add(BigInteger.ONE);
	    }
	}
    }

}
