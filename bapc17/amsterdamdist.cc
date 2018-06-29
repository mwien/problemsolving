#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int m, n;
    double r;
    cin >> m >> n >> r;
    int ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    double res = 0;
    res += r*abs(ay-by)/n;
    cout << res << endl;
    int y = min(ay,by);
    double R = r / n * y;
    res += M_PI*abs(ax-bx)*R/m;
    printf("%.12f\n", res);
}
