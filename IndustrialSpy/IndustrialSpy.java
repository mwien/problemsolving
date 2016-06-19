import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class IndustrialSpy {

    public static boolean nextPermutation(char[] a) {
	int i = a.length - 1;
	while(i > 0 && a[i-1] >= a[i]) {
	    i--;
	}
	if(i <= 0) {
	    return false;
	}
	int j = a.length - 1;
	while(a[j] <= a[i-1]) {
	    j--;
	}
	char tmp = a[i-1];
	a[i-1] = a[j];
	a[j] = tmp;

	j = a.length - 1;
	while(i < j) {
	    tmp = a[i];
	    a[i] = a[j];
	    a[j] = tmp;
	    i++;
	    j--;
	}
	return true;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int max = 10000000-1;
	boolean[] isPrime = new boolean[max+1];
	for(int i = 2; i <= max; i++) isPrime[i] = true;
	for(int i = 2; i*i <= max; i++) {
	    if(isPrime[i])
		for(int j = i*i; j <= max; j+= i)
		    isPrime[j] = false;
	}
	int C = Integer.parseInt(br.readLine());
	for(int c = 0; c < C; c++) {
	    String in = br.readLine();
	    char[] dig = in.toCharArray();
	    boolean[] vis = new boolean[max+1];
	    int n = dig.length;
	    int cnt = 0;
	    for(int i = 1; i < (1 << n); i++) {
		int k = 1;
		ArrayList<Character> nums = new ArrayList<Character>();
		for(int j = 0; j < n; j++) {
		    if((k & i) == k) {
			nums.add(dig[j]);
		    }
		    k = (k << 1);
		}
		char[] cur = new char[nums.size()];
		for(int j = 0; j < nums.size(); j++) {
		    cur[j] = nums.get(j);
		}
		Arrays.sort(cur);
		while(true) {
		    int tp = Integer.parseInt(String.valueOf(cur));
		    if(isPrime[tp]) cnt++;
		    if(vis[tp] && isPrime[tp]){
			cnt--;
		    }
		    vis[tp] = true;
		    if(!nextPermutation(cur)) break;
		}
	    }
	    System.out.println(cnt);
	}
    }

}
