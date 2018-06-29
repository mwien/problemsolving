import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int anzahl = scanner.nextInt();
        int laenge = scanner.nextInt(); 

        LinkedList<Integer> queue = new LinkedList();
        Boolean[] visited = new Boolean[(int) Math.pow(2,laenge)];
        Arrays.fill(visited, false);
        for (int i=0; i<anzahl; i++){
            String a = scanner.next();
            queue.push(Integer.parseInt(a,2));
            visited[Integer.parseInt(a, 2)] = true;
        }

        int zuletztBesucht = 0;

        while(!queue.isEmpty()){
            int v = queue.pollLast();
            //System.out.println(v + "\n");
        for(int i = 0; i < laenge; ++i) {
                //System.out.println(a);
        int a = v ^(1<<i);
                if (!visited[a]){
                    queue.push(a);
                    visited[a] = true;
                    zuletztBesucht = a;
                }
            }
        }
    String res = Integer.toBinaryString(zuletztBesucht);
    while(res.length() != laenge) res = "0" + res;
        System.out.println(res);
    }
} 
