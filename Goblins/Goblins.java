import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class Goblins {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int g = scan.nextInt();
		TreeSet<Integer>[] gp = new TreeSet[10001];
		HashMap<Integer, Integer>[] cnt = new HashMap[10001];
		for (int i = 0; i <= 10000; i++) {
			gp[i] = new TreeSet<Integer>();
			cnt[i] = new HashMap<Integer, Integer>();
		}
		for (int i = 0; i < g; i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			if(!gp[x].contains(y)){
				gp[x].add(y);
				cnt[x].put(y, 1);
			} else {
				cnt[x].put(y, cnt[x].get(y)+1);
			}
		}

		int m = scan.nextInt();
		for (int i = 0; i < m; i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			int r = scan.nextInt();

			for (int j = Math.max(x-r,  0); j <= Math.min(10000, x+r); j++) {
				if(j < gp.length && gp[j].size() > 0){
					int dx = Math.abs(x-j);
					int upper = y + (int) Math.sqrt(r*r - dx*dx);
					int lower = 2*y - upper;
					
					for(int p : gp[j].subSet(lower, true, upper, true).toArray(new Integer[0])){
						gp[j].remove(p);
					}
				}
			}
		}
		int out = 0;
		for(int i = 0; i <= 10000; i++){
			for(int j : gp[i]){
				out += cnt[i].get(j);
			}
		}
		System.out.println(out);		

		scan.close();
	}

}
