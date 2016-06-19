import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Bridges {

    public static int findmax(int a, int aB, int b, int bB) {
	if(a > b) {
	    return 1;
	} else if(b > a) {
	    return 2;
	} else  {
	    if(aB <= bB) {
		return 1;
	    } else {
		return 2;
	    }
	}
    }

    public static void main(String[] args) throws IOException {
	//reading input
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String in = br.readLine();
	int TC = Integer.parseInt(in);
	for(int t = 0; t < TC; t++) {
	    in = br.readLine();
	    int nN = Integer.parseInt(in);
	    String[] otN = new String[nN+1];
	    int[] tvN = new int[nN+1];
	    for(int i = 1; i < nN+1; i++) {
		in = br.readLine();
		String ina[] = in.split(" ");
		otN[i] = ina[1];
		tvN[i] = Integer.parseInt(ina[2]);
	    }
	    in = br.readLine();
	    int nS = Integer.parseInt(in);
	    String[] otS = new String[nS+1];
	    int[] tvS = new int[nS+1];
	    for(int i = 1; i < nS+1; i++) {
		in = br.readLine();
		String ina[] = in.split(" ");
		otS[i] = ina[1];
		tvS[i] = Integer.parseInt(ina[2]);
	    }
	    
	    //computing solution with DP
	    int[][] T = new int[nN+1][nS+1];
	    int[][] nB = new int[nN+1][nS+1];
	    for(int i = 0; i < nN+1; i++) {
		for(int j = 0; j < nS+1; j++) {
		    if(i == 0 || j == 0) {
			T[i][j] = 0;
			nB[i][j] = 0;
		    } else {
			int fm;
			int fp = findmax(T[i-1][j], nB[i-1][j], T[i][j-1], nB[i][j-1]);
			if(fp == 1) {
			    fm = T[i-1][j];
			    int sp = findmax(fm, nB[i-1][j], T[i-1][j-1] + tvN[i] + tvS[j], nB[i-1][j-1]);
			    if(!otN[i].equals(otS[j])) {
				T[i][j] = fm;
				nB[i][j] = nB[i-1][j];
			    } else {
				if(sp == 1) {
				    T[i][j] = fm;
				    nB[i][j] = nB[i-1][j];
				} else {
				    T[i][j] = T[i-1][j-1] + tvN[i] + tvS[j];
				    nB[i][j] = nB[i-1][j-1] + 1;
				}
			    }
			} else {
			    fm = T[i][j-1];
			    int sp = findmax(fm, nB[i][j-1], T[i-1][j-1] + tvN[i] + tvS[j], nB[i-1][j-1]);

			    if(!otN[i].equals(otS[j])) {
				T[i][j] = fm;
				nB[i][j] = nB[i][j-1];
			    } else {
				if(sp == 1) {
				    T[i][j] = fm;
				    nB[i][j] = nB[i][j-1];
				} else {
				    T[i][j] = T[i-1][j-1] + tvN[i] + tvS[j];
				    nB[i][j] = nB[i-1][j-1] + 1;
				}
			    }
			}
		    }
		}
	    }
	    System.out.println(T[nN][nS] + " " + nB[nN][nS]);
	}
    }


}