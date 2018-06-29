#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <assert.h>
using namespace std;

enum Op {
	Sin, Cos, Tan, Plus, Minus, Mul, X
};

vector<Op> parse(vector<string>& code) {
	vector<Op> out;
	Op x;
	for (auto& c: code) {
		if (c=="sin")
			x= Sin;
		if (c=="cos")
			x= Cos;
		if (c=="tan")
			x= Tan;
		if (c=="+")
			x= Plus;
		if (c=="-")
			x= Minus;
		if (c=="*")
			x= Mul;
		if (c=="x")
			x= X;
		out.push_back(x);
	}
	return out;
}

double eval(vector<Op>& code, double x) {
	vector<double> stack;
	for (auto& c: code) {
		if (c==X)
			stack.push_back(x);
		if (c==Sin)
			stack.back()=sin(stack.back());
		if (c==Cos)
			stack.back()=cos(stack.back());
		if (c==Tan)
			stack.back()=tan(stack.back());
		if (c==Plus) {
			auto a = stack.back();
			stack.pop_back();
			stack.back() += a;
		}
		if (c==Minus) {
			auto a = stack.back();
			stack.pop_back();
			stack.back() -= a;
		}
		if (c==Mul) {
			auto a = stack.back();
			stack.pop_back();
			stack.back() *= a;
		}
	}
	return stack.back();
}

int num_samples = 10000;
double epsilon = 0.0001;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n==0)
			return 0;
		vector<string> vs(n);
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			vs[i] = s;
		}
		auto formula = parse(vs);

		bool failed = false;
		uniform_real_distribution<double> dist(0,3);
		mt19937 rd;;
		for (int i=0; i<num_samples; i++)  {
			if (abs(eval(formula, dist(rd)))>epsilon) {
				failed = true;
				break;
			}
		}

		if (!failed)
			cout << "Identity" << endl;
		else 
			cout << "Not an identity" << endl;
	}
}
