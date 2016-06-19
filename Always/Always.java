import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.math.BigInteger;

public class Always {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int cse = 1;
	while(true) {
	    String in = br.readLine();
	    if(in.equals(".")) break;
	    String[] sp = in.split("/");
	    String pol = sp[0].substring(1, sp[0].length()-1);
	    int[] c = new int[101];
	    ArrayList<Character> signs = new ArrayList<Character>();
	    if(pol.charAt(0) == '-') {
		pol = pol.substring(1);
		signs.add('-');
	    } else {
		signs.add('+');
	    }
	    for(int i = 1; i < pol.length(); i++) {
		if(pol.charAt(i) == '+') {
		    signs.add('+');
		} else if(pol.charAt(i) == '-') {
		    signs.add('-');
		}
	    }
	    pol = pol.replaceAll("-", "+");
	    String[] ps = pol.split("[+]");
	    for(int i = 0; i < ps.length; i++) {
		String r = ps[i];
		int npos = -1;
		int hpos = -1;
		int exp = -1;
		int coeff = -1;
		for(int j = 0; j < r.length(); j++) {
		    if(r.charAt(j) == 'n') {
			npos = j;
		    }
		    if(r.charAt(j) == '^') {
			hpos = j;
		    }
		}
		//find coeff
		if(npos == 0) {
		    coeff = 1;
		} else if(npos == -1) {
		    coeff = Integer.parseInt(r);
		} else {
		    coeff = Integer.parseInt(r.substring(0, npos));
		}
		//find exp
		if(npos == -1) {
		    exp = 0;
		} else if(npos == r.length()-1) {
		    exp = 1;
		} else {
		    exp = Integer.parseInt(r.substring(hpos+1));
		}
		if(signs.get(i) == '-') {
		    coeff *= -1;
		}
		c[exp] = coeff;
	    }
	    
	    
	    boolean corr =  true;
	    BigInteger div = new BigInteger(sp[1]);
	    for(int i = 0; i < c.length; i++) {
		BigInteger sum = new BigInteger("0");
		BigInteger x = new BigInteger(Integer.toString(i));
		for(int j = 0; j < c.length; j++) {
		    if(c[j] == 0) continue;
		    BigInteger coeff = new BigInteger(Integer.toString(c[j]));
		    //BigInteger exp = new BigInteger(Integer.toString(j));
		    sum = sum.add(coeff.multiply(x.pow(j)));
		}
		
		if(!sum.mod(div).equals(new BigInteger("0"))) {
		    corr = false;
		}
	    }
	    System.out.print("Case " + cse++ + ": ");
	    System.out.println(corr ? "Always an integer" : "Not always an integer");
	}
    }

}
