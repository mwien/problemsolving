import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class Blocks {

    public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n = Integer.parseInt(br.readLine());
	ArrayList<ArrayList<Integer>> bl = new ArrayList<ArrayList<Integer>>();
	for(int i = 0; i < n; i++) {
	    bl.add(new ArrayList<Integer>());
	}
	for(int i = 0; i < n; i++) {
	    bl.get(i).add(i);
	}
	int[] pos = new int[n];
	for(int i = 0; i < n; i++) {
	    pos[i] = i;
	}
	while(true) {
	    String input = br.readLine();
	    String[] in = input.split(" ");
	    if(in[0].equals("quit")) break;
	    int a = Integer.parseInt(in[1]);
	    int b = Integer.parseInt(in[3]);
	    int aw = pos[a] % n;
	    int ah = pos[a] / n;
	    int bw = pos[b] % n;
	    int bh = pos[b] / n;
	    if(aw == bw) continue;
	    if(in[0].equals("move")) {
		if(in[2].equals("onto")) {
		    for(int i = ah+1; i < bl.get(aw).size(); i++) {
			bl.get(bl.get(aw).get(i)).add(bl.get(aw).get(i));
			pos[bl.get(aw).get(i)] = bl.get(aw).get(i);
		    }
		    bl.get(aw).subList(ah+1, bl.get(aw).size()).clear();
		    for(int i = bh+1; i < bl.get(bw).size(); i++) {
			bl.get(bl.get(bw).get(i)).add(bl.get(bw).get(i));
			pos[bl.get(bw).get(i)] = bl.get(bw).get(i);
		    }
		    bl.get(bw).subList(bh+1, bl.get(bw).size()).clear();
		    bl.get(aw).remove(ah);
		    bl.get(bw).add(a);
		    pos[a] = (bh+1)*n + bw;
		} else {
		    for(int i = ah+1; i < bl.get(aw).size(); i++) {
			bl.get(bl.get(aw).get(i)).add(bl.get(aw).get(i));
			pos[bl.get(aw).get(i)] = bl.get(aw).get(i);
		    }
		    bl.get(aw).subList(ah+1, bl.get(aw).size()).clear();
		    bl.get(aw).remove(ah);
		    bl.get(bw).add(a);
		    pos[a] = (bl.get(bw).size()-1) * n + bw;
		}
	    } else {
		if(in[2].equals("onto")) {
		    for(int i = bh+1; i < bl.get(bw).size(); i++) {
			bl.get(bl.get(bw).get(i)).add(bl.get(bw).get(i));
			pos[bl.get(bw).get(i)] = bl.get(bw).get(i);
		    }
		    bl.get(bw).subList(bh+1, bl.get(bw).size()).clear();
		    for(int i = ah; i < bl.get(aw).size(); i++) {
			bl.get(bw).add(bl.get(aw).get(i));
			pos[bl.get(aw).get(i)] = (bl.get(bw).size()-1) * n + bw;
		    }
		    bl.get(aw).subList(ah, bl.get(aw).size()).clear();
		} else {
		    for(int i = ah; i < bl.get(aw).size(); i++) {
			bl.get(bw).add(bl.get(aw).get(i));
			pos[bl.get(aw).get(i)] = (bl.get(bw).size()-1) * n + bw;
		    }
		    bl.get(aw).subList(ah, bl.get(aw).size()).clear(); 
		}
	    }
	    
	}
	for(int i = 0; i < n; i++) {
	    System.out.print(i + ":");
	    for(int j = 0; j < bl.get(i).size(); j++) {
		System.out.print(" " + bl.get(i).get(j));
	    }
	    System.out.println();
	}

    }

}
