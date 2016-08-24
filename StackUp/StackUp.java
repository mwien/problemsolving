import java.util.Scanner;

public class StackUp {

    public static void shuffle(int[] deck, int[] shuffle) {
	int[] tmp = new int[52];
	for(int i = 0; i < 52; i++) {
	    tmp[i] = deck[shuffle[i]];
	}
	for(int i = 0; i < 52; i++) {
	    deck[i] = tmp[i];
	}
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int T = s.nextInt();

	String[] vals = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
	String[] suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
	
	for(int t = 0; t < T; t++) {
	    if(t > 0) System.out.println();
	    int n = s.nextInt();
	    int[][] shuffles = new int[n][52];
	    for(int i = 0; i < n; i++) {
		for(int j = 0; j < 52; j++) {
		    shuffles[i][j] = s.nextInt()-1;
		}
	    }
	    int[] deck = new int[52];
	    for(int i = 0; i < 52; i++) {
		deck[i] = i;
	    }
	    s.nextLine();
	    String input = "";
	    while(s.hasNext() && (input = s.nextLine()).length() > 0) {
		int N = Integer.parseInt(input)-1;
		shuffle(deck, shuffles[N]);
	    }
	    for(int i = 0; i < 52; i++) {
		System.out.println(vals[deck[i]%13] + " of "  + suits[deck[i]/13]);
	    }
	}

    }

}
