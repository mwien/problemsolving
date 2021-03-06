import java.util.Scanner;

public class Quiz {
    //(1 << n) -1
    public static int nextNumber(int x) {
	//break when larger than limit
	if(x == 0) return 0;
	int smallest = x & -x;
	int ripple = x + smallest;
	int new_smallest = ripple & -ripple;
	int ones  = ((new_smallest/smallest) >> 1) - 1;
	return ripple | ones;
    }

    public static void main(String[] args) {
	int abc = 35;
	for(int i = 0; i < 300; i++) {
	  abc = nextNumber(abc);
	  System.out.println(abc);
	}
	Scanner s = new Scanner(System.in);
	int c = 1;
	while(true) {
	    int N = s.nextInt();
	    if(N == 0) break;
	    s.nextLine();
	    int[] x = new int[2*N];
	    int[] y = new int[2*N];
	    for(int i = 0; i < 2 * N; i++) {
		String in = s.nextLine();
		String[] inA = in.split(" ");
		x[i] = Integer.parseInt(inA[1]);
		y[i] = Integer.parseInt(inA[2]);
	    }
	    double[][] dist = new double[2*N][2*N];
	    for(int i = 0; i < 2*N; i++) {
		for(int j = i + 1; j < 2*N; j++) {
		    double d = Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		    dist[i][j] = d;
		}
	    }
	    double[] g = new double[(1 << 2*N) + 1];
	    g[0] = 0;
	    for(int n = 1; n <= N; n++) {
		int startx = (1 << 2 * n) - 1;
		int X = startx;
		do {
		    if(X > (1 << 2*N)) break;
		    double min = Double.MAX_VALUE;
		    for(int i = 0; i < 2 * N; i++) {
			for(int j = i + 1; j < 2 * N; j++) {
			    if(((X & (1 << i)) != (1 << i)) || ((X & (1 << j)) != (1 << j))) continue;
			    double val = g[X & ((X^(1 << i))^(1 << j))] + dist[i][j];
			    if(val < min) {
				min = val;
			    }
			}
		    }
		    g[X] = min;
		    X = nextNumber(X);
		} while(startx != X);
	    }
	    System.out.print("Case " + c + ": ");
	    System.out.printf("%.2f\n", g[(1 << 2*N) - 1]);
	    c++;
	}
    }

}
