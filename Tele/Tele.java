import java.util.Scanner;

public class Tele {

    public static int[][] mult(int[][] a, int[][] b, int N) {
	int[][] res = new int[N][N];
	for(int i = 0; i < N; i++) {
	    for(int j = 0; j < N; j++) {
		for(int k = 0; k < N; k++) {
		    res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % 10000;
		}
	    }
	}
	return res;
    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while(sc.hasNext()) {
	    int N = sc.nextInt();
	    int L = sc.nextInt();
	    int S = sc.nextInt();
	    int T = sc.nextInt();
	    int[][] g = new int[N][N];
	    int[][] s = new int[N][N];
	    s[S-1][S-1] = 1;
	    for(int i = 0; i < N; i++) {
		for(int j = 0; j < 4; j++) {
		    int b = sc.nextInt();
		    g[i][b-1]++;
		}
	    }
	    //calc g^L
	    int[][] res = new int[N][N];
	    //start with I
	    for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
		    if(i == j) res[i][j] = 1;
		}
	    }
	    for(int i = 0; (1 << i) <= L; i++) {
		if(((1 << i) & L) == (1 << i)) {
		    res = mult(res, g, N);
		    //System.out.println(i + " " + L);
		}
		g = mult(g, g, N);
		// for(int j = 0; j < N; j++) {
		//     for(int k = 0; k < N; k++) {
		// 	System.out.print(g[j][k] + " ");
		//     }
		//     System.out.println();
		// }      	
	    }
	    // System.out.println("res");
	    // for(int j = 0; j < N; j++) {
	    // 	for(int k = 0; k < N; k++) {
	    // 	    System.out.print(res[j][k] + " ");
	    // 	}
	    // 	System.out.println();
	    // }		
	    // System.out.println("s");
	    // for(int j = 0; j < N; j++) {
	    // 	for(int k = 0; k < N; k++) {
	    // 	    System.out.print(s[j][k] + " ");
	    // 	}
	    // 	System.out.println();
	    // }		
	    
	    //calc s * res
	    res = mult(s, res, N);
	    // for(int i = 0; i < N; i++) {
	    // 	for(int j = 0; j < N; j++) {
	    // 	    System.out.print(res[i][j] + " ");
	    // 	}
	    // 	System.out.println();
	    // }
	    System.out.println(res[S-1][T-1]);
	}
    }

}
