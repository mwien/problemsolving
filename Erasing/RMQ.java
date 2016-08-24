import java.util.Scanner;


public class RMQ {
    
    public static void process(int[][] M, int[] A, int N) {
        for(int i = 0; i < N; i++) {
            M[i][0] = i;
        }
        
        for(int j = 1; 1 << j <= N; j++) {
            for(int i = 0; i + (1 << j) - 1 < N; i++) {
                if(A[M[i][j-1]] >= A[M[i+(1 << (j-1))][j-1]]) {
                    M[i][j] = M[i][j-1];
                } else {
                    M[i][j] = M[i + (1 << (j-1))][j-1];
                }
            }
        }
    }
    
    public static int query(int[][] M, int[] A, int N, int i, int j) {
        int k = (int) (Math.log(j - i + 1) / Math.log(2));
        if(A[M[i][k]] >= A[M[j- (1 << k) + 1][k]]) {
            return M[i][k];
        } else {
            return M[j - (1 << k) + 1][k];
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        int[] A = new int[n];
        int[][] queries = new int[m][2];
        for(int i = 0; i < n; i++) {
            A[i] = s.nextInt();
        }
        int size = (int) (Math.log(n)/Math.log(2)) + 1;
        int[][] M = new int[n][size];
        process(M, A, n);
        System.out.println(n + " " + size);
        for(int j = 0; j < size; j++) {
            for(int i = 0; i < n; i++) {
                System.out.print(M[i][j] + " ");
            }
            System.out.println();
        }
        for(int i = 0; i < m; i++) {
            queries[i][0] = s.nextInt();
            queries[i][1] = s.nextInt();
        }
        for(int i = 0; i < m; i++) {
            System.out.println(query(M, A, n, queries[i][0], queries[i][1]));
        }
    }

}
