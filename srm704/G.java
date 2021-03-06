import java.util.ArrayList;
import java.util.Scanner;

public class ConnectedComponentConstruction {
    public String[] construct(int[] s) {
     	int[] cnt = new int[s.length+1];
        String[] ret = new String[0];
        for(int i = 0; i < s.length; ++i) {
            if(s[i] > s.length || s[i] <= 0)  {
				return ret;
            }
            ++cnt[s[i]];
        }
        for(int i = 1; i < cnt.length; ++i) {
         	if(cnt[i] % i != 0) return ret;  
        }
        boolean[] vis = new boolean[s.length];
        ret = new String[s.length];
        ArrayList<ArrayList<Integer>> n = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < s.length; ++i) {
         	n.add(new ArrayList<Integer>());   
        }
        for(int i = 0; i < s.length; ++i) {
            if(vis[i]) continue;
            n.get(i).add(i);
            int nc = 1;
            for(int j = 0; j < s.length; ++j) {
            	if(nc >= s[i]) break;
                if(s[i] == s[j] && !vis[j]) {
                 	n.get(i).add(j);
                    vis[j] = true;
                    ++nc;
                }
            }
            for(int j = 1; j < n.get(i).size(); ++j) {
                int u = n.get(i).get(j);
                for(int k = 0; k < n.get(i).size(); ++k) {
                 	n.get(u).add(n.get(i).get(k));   
                }
            }
            System.err.println(n);
        }
        System.err.println(n);
        for(int i = 0; i < s.length; ++i) {
            char[] out = new char[s.length];
            for(int j = 0; j < s.length; ++j) {
                out[i] = 'N';
            }
            for(int j = 0; j < n.get(i).size(); ++j) {
                if(i != n.get(i).get(j)) {
					out[i] = 'Y';
                }
            }
            String o = "";
            for(int j = 0; j < s.length; ++j) {
             	o += out[j];   
            }
            System.err.println(o);
            ret[i] = o;
        }
        return ret;
    }
    public static void main() {
	Scanner s = new Scanner(System.in);
	int n = s.nextInt();
	int[] s = new int[n];
	for(int i = 0; i < n; ++i) {
	    s[i] = s.nextInt();
	}
    }
}
