import java.util.Scanner;

public class UN {

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int cnt = 0;
	while(s.hasNext()) {
	    if(cnt++ > 0) System.out.println();
	    int n = s.nextInt();
	    int h = n;
	    int w = n;
	    int l = 2;
	    System.out.println(h + " " + w + " " + l);
	    for(int i = 0; i < n; i++) {
		char x;
		if(i < 26) x = (char) ('A' + i);
		else x = (char) ('a' + (i-26));
		for(int j = 0; j < n; j++) {
		    char cur;
		    if(j < 26) cur = (char) ('A' + j);
		    else cur = (char) ('a' + (j-26));
		    System.out.print(cur);
		}
		System.out.println();
		for(int j = 0; j < n; j++) {
		    System.out.print(x);
		}
		System.out.println();
		if(i < n-1) System.out.println();
	    }
	}

    }
    
}
