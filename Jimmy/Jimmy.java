import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Jimmy {

    public static final String VERB = "(hate|love|know|like|VERB)s*";
    public static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    public static final String ARTICLE = "(a|the)";
    public static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
    public static final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
    public static final String ACTION = ACTIVE_LIST+ " " + VERB + " " + ACTIVE_LIST;
    public static final String STATEMENT = ACTION + "( , " + ACTION + ")*";


    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String riddle;
	while((riddle = br.readLine()) != null) {
	    System.out.println(riddle.matches(STATEMENT) ? "YES I WILL" : "NO I WON'T");
	}
    }


}
