
import java.util.*;


public class Sort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Item> items = new ArrayList<>();
		boolean lastWasString = false;
		int lastNumber;
		String[] content =sc.nextLine().split(" ");
		while(!content[0].equals("0"))
		{
			for(int i=0; i<content.length; i++)
			{
				if(isNotANumber(content[i]))
				{
					if(lastWasString)
					{
						Item array = items.get(items.size()-1);
						array.name = array.name+" "+content[i];
						items.set(items.size()-1, array);
					}
					else
					{
						Item array = items.get(items.size()-1);
						array.name = content[i];
						items.set(items.size()-1, array);
					}
					lastWasString= true;
				}
				else
				{
					Item array = new Item("", Integer.parseInt(content[i]));
					items.add(array);
					lastWasString = false;
				}
			}

			content =sc.nextLine().split(" ");
		}
		Collections.sort(items);
		for(int i=0; i<items.size(); i++)
			System.out.println(items.get(i).name+" "+items.get(i).anzahl);
	}
	public static boolean isNotANumber(String input){
		if(input.charAt(0)=='0' || input.charAt(0)=='1'|| input.charAt(0)=='2' || input.charAt(0)=='3' || input.charAt(0)=='4' || input.charAt(0)=='5' || input.charAt(0)=='6' || input.charAt(0)=='7' || input.charAt(0)=='8' || input.charAt(0)=='9')
			return false;
		else
			return true;
	}

}

class Item implements Comparable<Item>
{
	String name;
	int anzahl;
	
	public Item(String name, int anzahl){
		this.name= name;
		this.anzahl=anzahl;		
	}
	
	public int compareTo(Item other) {
		int ergebnis = this.name.compareTo(other.name);
		if(ergebnis != 0)
		{
			return ergebnis;
		}
		return Integer.compare(this.anzahl, other.anzahl);
	}
	   
}