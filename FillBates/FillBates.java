import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class FillBates {

    public static ArrayList<ArrayList<Integer>> pos = new ArrayList<ArrayList<Integer>>();

    public static int binarySearch(int ind, int pst) {
	ArrayList<Integer> rn = pos.get(ind);
	int lo = 0;
	int hi = rn.size()-1;
	int mid = -1;
	while(lo <= hi) {
	    mid = (int) (((lo + hi) / 2.0) + 0.6);
	    if(rn.get(mid) < pst) {
		lo = mid+1;
	    } else {
		hi = mid-1;
	    }
	}
	return lo;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String c = br.readLine();
	//preprocessing
	for(int i = 0; i < 52; i++) {
	    pos.add(new ArrayList<Integer>());
	}
	for(int i = 0; i < c.length(); i++) {
	    char cur = c.charAt(i);
	    if('A' <= cur && 'Z' >= cur) {
		pos.get(cur - 'A').add(i);
	    } else {
		pos.get(cur - 'a' + 26).add(i);
	    }
	}
	//queries
	int Q = Integer.parseInt(br.readLine());
	//System.out.println(pos);
	for(int i = 0; i < Q; i++) {
	    String q = br.readLine();
	    int pst = 0;
	    boolean poss = true;
	    int first = -1;
	    for(int j = 0; j < q.length(); j++) {
		char n = q.charAt(j);
		int ind;
		if('A' <= n && 'Z' >= n) {
		    ind = n - 'A';
		} else {
		    ind = n - 'a' + 26;
		}
		int res = binarySearch(ind, pst);
		//System.out.println("R" + res + " " + pst);
		if(res + 1 < pos.get(ind).size() && pos.get(ind).get(res) < pst) {
		    pst = pos.get(ind).get(res + 1) + 1;
		} else if(res + 1 > pos.get(ind).size() || (res + 1 >= pos.get(ind).size() && pos.get(ind).get(res) < pst)) {
		    poss = false;
		    break;
		} else {
		    pst = pos.get(ind).get(res) + 1;
		}
		if(j == 0) first = pst - 1;
		//System.out.println(pst);
	    }
	    System.out.println(poss ? "Matched " + first + " " + (pst -1) : "Not matched");
	}
    }

}
