import java.util.Scanner;

public class Hello {

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int n = s.nextInt();
	long max = Integer.MIN_VALUE;
	for(int i = 0; i < n; i++) {
	    long cur = s.nextLong();
	    if(cur > max) max = cur;
	}
	System.out.println(max * max * max);
    }

}
