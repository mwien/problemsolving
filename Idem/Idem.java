import java.util.Scanner;
import java.math.BigInteger;

public class Idem {

    public static BigInteger fac(int f) {
	BigInteger res = BigInteger.ONE;
	while(f > 1) {
	    res = res.multiply(new BigInteger(Integer.toString(f)));
	    --f;
	}
	return res.subtract(BigInteger.ONE);
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int t = s.nextInt();
	for(int i = 0; i < t; i++) {
	    System.out.println(fac(s.nextInt()).mod(new BigInteger("1000000007")));
	}
    }

}
