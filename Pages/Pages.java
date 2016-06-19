import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class Pages {
    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int gcnt = 1;
	while(true) {
	    HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
	    ArrayList<Integer> from = new ArrayList<Integer>();
	    ArrayList<Integer> to = new ArrayList<Integer>();
	    int cnt = 0;
	    while(true) {
		int a = s.nextInt();
		int b = s.nextInt();
		if(a == 0 && b == 0) break;
		if(hm.containsKey(a)) a = hm.get(a);
		else {
		    hm.put(a, cnt++);
		    a = cnt - 1;
		}
		if(hm.containsKey(b)) b = hm.get(b);
		else {
		    hm.put(b, cnt++);
		    b = cnt - 1;
		}
		from.add(a);
		to.add(b);
	    }
	    if(from.isEmpty() && to.isEmpty()) break;
	    int[][] g = new int[cnt][cnt];
	    for(int i = 0; i < cnt; i++) {
		for(int j = 0; j < cnt; j++) {
		    g[i][j] = Integer.MAX_VALUE;
		}
	    }
	    for(int i = 0; i < from.size(); i++) {
		g[from.get(i)][to.get(i)] = 1;
	    }
	    for(int k = 0; k < g.length; k++) {
		for(int i = 0; i < g.length; i++) {
		    for(int j = 0; j < g.length; j++) {
			if(g[i][k] + g[k][j] < g[i][j] && g[i][k] < Integer.MAX_VALUE && g[k][j] < Integer.MAX_VALUE) {
			    g[i][j] = g[i][k] + g[k][j];
			}
		    }
		}
	    }
	    int sum = 0;
	    for(int i = 0; i < g.length; i++) {
		for(int j = 0; j < g.length; j++) {
		    if(i != j) sum += g[i][j];
		}
	    }
	    int div = g.length * (g.length - 1);
	    System.out.print("Case " + gcnt++ + ": average length between pages = ");
	    System.out.printf("%.3f", (double) sum / div);
	    System.out.println(" clicks");
	}
    }

}