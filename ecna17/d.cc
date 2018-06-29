#include <iostream>
#include <queue>

using namespace std;


int main() {
    const int N_CMD = 100;
    
    deque<string> cmd;
    int i = 0;
    int n = 0;
    int students, k;
    string tmp;
    cin >>students >> k;
    while(cin >> tmp)
    {
	if (tmp != "undo")
	{
	    cmd.push_front(tmp);
	    n += stoi(tmp);
	    n = (((n % students) + students) % students);
	    i++;
	} else {
	    int steps;
	    cin >> steps;
	    for ( int j = 0; j < steps; ++j)
	    {
		n -= stoi(cmd.front());
		cmd.pop_front();
		n = (((n % students) + students) % students);
	    }
	}
     }
    cout << n << endl;
}
