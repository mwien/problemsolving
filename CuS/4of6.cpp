#include <iostream>
using namespace std;

short hd(short x, short y)
{
  short dist = 0;
  char val = x^y;
  while(val)
  {
    ++dist; 
    val &= val - 1;
  }
  return dist;
}

int main()
{
    short w[(1 << 6)];
    for(int i = 0; i < (1 << 6); i++) {
	w[i] = i;
    }

    for(int i1 = 0; i1 < 64; i1++) {
	for(int i2 = 0; i2 < 64; i2++) {
	    if(i1 == i2) continue;
	    for(int i3 = 0; i3 < 64; i3++) {
		if(i3 == i1 || i3 == i2) continue;
		for(int i4 = 0; i4 < 64; i4++) {
		    if(i4 == i1 || i4 == i2 || i4 == i3) continue;
		    for(int i5 = 0; i5 < 64; i5++) {
			if(i5 == i1 || i5 == i2 || i5 == i3 || i5 == i4) continue;
			if(hd(w[i1], w[i2]) > 2 && hd(w[i1], w[i3]) > 2 && hd(w[i1],w[i4]) > 2 && hd(w[i1], w[i5]) > 2 && hd(w[i2], w[i3]) > 3 && hd(w[i2], w[i4]) > 3 && hd(w[i2], w[i5]) > 3 && hd(w[i3], w[i4]) >  3 && hd(w[i3], w[i5]) > 3 && hd(w[i4], w[i5]) > 3) {
			    cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;
			}
		    }
		}
	    }
	}
    }
}
