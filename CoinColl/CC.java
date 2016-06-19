import java.util.Scanner;

public class CC {

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int T = s.nextInt();
	for(int i = 0; i < T; i++) {
	    int n = s.nextInt();
	    int[] C = new int[n];
	    for(int j = 0; j < n; j++) {
		C[j] = s.nextInt();
	    }
	    int sum = 0;
	    int coins = 0;
	    for(int j = 0; j < n-1; j++) {
		if(sum + C[j] < C[j+1]) {
		    sum += C[j];
		    coins++;
		}
	    }
	    System.out.println(coins+1);
	}
    }

}