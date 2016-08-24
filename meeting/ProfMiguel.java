import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

//Bellman-Ford fuer me and prof, smallest sum StartM to x plus StartP to x
public class ProfMiguel {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = Integer.parseInt(sc.nextLine());
		while(number!=0){
			ArrayList<Road> me = new ArrayList<>();
			ArrayList<Road> prof = new ArrayList<>();
			ArrayList<String> places = new ArrayList<>();
			for(int i=0 ; i<number ; i++){
				String[] input = sc.nextLine().split(" ");
				// Young
				if(input[0].equals("Y")){
					me.add(new Road(input[2],input[3],Long.parseLong(input[4])));
					if(input[1].equals("B")){
						me.add(new Road(input[3], input[2],Long.parseLong(input[4])));
					}
					if(!places.contains(input[2]))
						places.add(input[2]);
					if(!places.contains(input[3]))
						places.add(input[3]);
				}
				// Old
				else{
					prof.add(new Road(input[2],input[3],Long.parseLong(input[4])));
					if(input[1].equals("B")){
						prof.add(new Road(input[3], input[2],Long.parseLong(input[4])));
					}
					if(!places.contains(input[2]))
						places.add(input[2]);
					if(!places.contains(input[3]))
						places.add(input[3]);
				}
			}
			String[] start = sc.nextLine().split(" ");
			if(!places.contains(start[0]))
				places.add(start[0]);
			int startMe = places.indexOf(start[0]);
			if(!places.contains(start[1]))
				places.add(start[1]);
			int startProf = places.indexOf(start[1]);
				//gek"urzter Bellman-Ford fuer me und prof
				//Ausgabe: Matrizen distMe(places.size, places.size) distProf(places.size, places.size)
				// wenn kein Weg verfuegbar Long.MAX_VALUE (entspricht unendlich)
				
				/**
				 * Me
				 */
				long [] distMe = new long[places.size()];
				for(int u=0; u<places.size(); u++){
						if(u!=startMe)
							distMe[u] = Long.MAX_VALUE;
						else
							distMe[u] = 0;
				}
				for(int u=0; u<places.size()-1; u++){
					for(Road r : me){
						long distStart = distMe[places.indexOf(r.getStart())];
						long distEnd = distMe[places.indexOf(r.getEnd())];
						if(distStart + r.getEnergy() < distEnd && distStart < Long.MAX_VALUE){
							distMe[places.indexOf(r.getEnd())] = distStart + r.getEnergy();
						}
					}
				}
				
				/**
				 * Prof
				 */
				long [] distProf = new long[places.size()];
				for(int u=0; u<places.size(); u++){
					if(u!=startProf)
						distProf[u] = Long.MAX_VALUE;
					else
						distProf[u] = 0;
				}
				for(int u=0; u<places.size()-1; u++){
					for(Road r : prof){
						long distStart = distProf[places.indexOf(r.getStart())];
						long distEnd = distProf[places.indexOf(r.getEnd())];
						if(distStart + r.getEnergy() < distEnd && distStart<Long.MAX_VALUE){
							distProf[places.indexOf(r.getEnd())] = distStart + r.getEnergy();
						}
					}
				}
				
				// die kuerzeste Gesamtdistanz finden
				ArrayList<Long> distances = new ArrayList<>();
				int stop = places.size();
				for(int j = 0 ; j<stop; j++){
					Long me1 =distMe[j];
					Long prof1 = distProf[j];
					if(me1.equals(Long.MAX_VALUE) || prof1.equals(Long.MAX_VALUE)){
						places.remove(j-(stop-places.size()));
					}else{
						distances.add(me1+prof1);
					}
				}
				if(places.size()==0){
					System.out.println("You will never meet.");
				}else{
					ArrayList<Integer> output = minimum(distances, places);
					System.out.print(distances.get(output.get(0)));
					for(int k =0; k<output.size(); k++){
						System.out.print(" "+places.get(output.get(k)));
					}
					System.out.println("");
				}
			
			number = Integer.parseInt(sc.nextLine());
		}
	}

	public static ArrayList<Integer> minimum(ArrayList<Long> distances, ArrayList<String> places){
		Long min = Long.MAX_VALUE;
		ArrayList<Integer> indices = new ArrayList<>();
		for(int i = 0; i< distances.size(); i++){
			if(distances.get(i)<min){
				min=distances.get(i);
				indices = new ArrayList<>();
				indices.add(i);
			}else if(distances.get(i)==min){
				indices.add(i);
			}
		}
		ArrayList<String> a = new ArrayList<>();
		for(int i: indices){
			a.add(places.get(i));
		}
		Collections.sort(a);
		ArrayList<Integer> output = new ArrayList<>();
		for(int i = 0; i<a.size(); i++){
			output.add(places.indexOf(a.get(i)));
		}
		return output;
	}
}

class Road
{
	String start;
	String end;
	long energy;
	
	Road(String a, String b, long c){
		this.start=a;
		this.end=b;
		this.energy=c;
	}
	public String getStart() 	{return start;}
	public String getEnd() 		{return end;}
	public long getEnergy() 	{return energy;}
}
