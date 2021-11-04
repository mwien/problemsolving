import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class c {
    public static void main(String[] args) {
	Kattio io = new Kattio(System.in);
	int n = io.getInt();
	int[] l = new int[n];
	int[] r = new int[n];
	for(int i = 0; i < n; ++i) {
	    l[i] = io.getInt();
	    r[i] = io.getInt();
	}
	int p = io.getInt();
	int[] x = new int[p];
	for(int i = 0; i < p; ++i) {
	    x[i] = io.getInt();
	}
	HashMap<Integer, ArrayList<Integer>> cxs = new HashMap<Integer, ArrayList<Integer>>();
	int px = 0;
	for(int i = 0; i < n; ++i) {
	    cxs.put(i, new ArrayList<Integer>());
	    int counter = 0;
	    if(px > 0) {
		--px;
	    }
	    while(px < p && x[px] < l[i]) {
		++px;
	    }
	    while(px < p && x[px] <= r[i]) {
		cxs.get(i).add(x[px]);
		++counter;
		++px;
	    }
	    if(counter > 2) {
		io.println("impossible");
		io.flush();
		io.close();
		return;
	    }
	}
	LinkedList<Integer> add = new LinkedList<Integer>();
	for(int i = 0; i < n; ++i) {
	    if(cxs.get(i).size() >= 2) {
		continue;
	    }
	    if(cxs.get(i).size() == 0) {
		if(cxs.containsKey(i+1) && cxs.get(i+1).size() < 2 && l[i+1] == r[i]) {
		    cxs.get(i+1).add(r[i]);
		    cxs.get(i).add(r[i]);
		    add.add(r[i]);
		    cxs.get(i).add(l[i]+1);
		    add.add(l[i]+1);
		} else {
		    cxs.get(i).add(l[i]+1);
		    add.add(l[i]+1);
		    cxs.get(i).add(l[i]+2);
		    add.add(l[i]+2);
		}
	    }
	    if(cxs.get(i).size() ==1) {
		if(cxs.get(i).get(0) != r[i]) {
		    if(cxs.containsKey(i+1) && cxs.get(i+1).size() < 2 && l[i+1] == r[i]) {
			cxs.get(i+1).add(r[i]);
			cxs.get(i).add(r[i]);
			add.add(r[i]);
		    } else {
			int set = cxs.get(i).get(0);
			if(set - 1 > l[i]) {
			    cxs.get(i).add(set-1);
			    add.add(set-1);
			} else {
			    cxs.get(i).add(set+1);
			    add.add(set+1);
			}
		    }
	    } else {
		    cxs.get(i).add(r[i]-1);
		    add.add(r[i]-1);
		}
	    } 
	}
	io.println(add.size());
	for(Integer a : add) {
	    io.print(a);
	    io.print(" ");
	}
	io.print("\n");
	
	io.flush();
	io.close();
    }
}


class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (Exception e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}


