
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
bool compare(int i, int j){ return (i > j);}
double rating(int a, int b){
    return (double)(a / (double) (a+b));
    
}
double matrix[20][5000];
int main(){
	int n;
	cin >> n;
    
	int dale, current;
	vector<int> contestants, contestants_old;
	cin >> dale;
	for(int i = 0; i<(n-1); i++){
		cin >> current;
		contestants_old.push_back(current);
	}
    sort(contestants_old.begin(), contestants_old.end(), compare);
    contestants_old.push_back(dale);
    int l = 0;
    while(n > (1<<l)){
        l++;
    }
    for(int i = 0; i < (n - ((1 << l) - n)); ++i) {
	contestants.push_back(contestants_old[i]);
    }
    for(int i = (n - ((1 << l ) - n)); i < n; ++i) {
	contestants.push_back(0);
	contestants.push_back(contestants_old[i]);
    }

    int logn = l;
  
    
    for(int j = 0; j < (1 << l); j++){
        matrix[0][j] = 1;
    }
    for(int i = 1; i <= logn; i++){
        
        for(int j = 0; j < (1 << l)/ (1 << (i-1)); j+= 2){
            
       
            
            for(int k = j*(1 << (i - 1)); k < (j +1)* (1 << (i - 1)); k++){
                double summe = 0.0d;
                if(contestants[k] == 0){
                    matrix[i][k] = 0;
		} else{
                    for(int l = (j+1)*(1 << (i - 1)); l < (j + 2)*(1 << (i - 1)); l++){
                     
                        double r = rating(contestants[k], contestants[l]);
                        summe += matrix[i-1][k] * matrix[i-1][l] * r;
                        
                    }
                    matrix[i][k] = summe;
                    
                }
                
            }
           
            for(int k = (j+1)*(1 << (i - 1)); k < (j+2)*(1 << (i - 1)); k++){
                double summe = 0.0d;
                if(contestants[k] == 0){
                    matrix[i][k] = 0;
                } else{
                    for(int l =  j*(1 << (i - 1)); l < (j+1)*(1 << (i - 1)); l++){
                        
                        double r = rating(contestants[k], contestants[l]);
                        summe += matrix[i-1][k] * matrix[i-1][l] * r;
                        
                    }
                    matrix[i][k] = summe;
                }
            }
            
        }
    }
    
    
    
    printf("%.10f\n", matrix[logn][(1<<l)-1]);
}
    
	
    
	
	
    
