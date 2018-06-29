#include<iostream>
#include<complex>

using namespace std;

int main()
{
    double ta, tb;
    cin >> ta >> tb;
    complex<double> l(ta, tb);
    cin >> ta >> tb;
    complex<double> d(ta, tb);
    cin >> ta >> tb;
    complex<double> cb(ta, tb);
    double rb;
    cin >> rb;
    cin >> ta >> tb;
    complex<double> cr(ta, tb);
    double rr;
    cin >> rr;
    double d1 = abs(cr-l);
    double d2 = abs(cr-d);
    double s1 = sqrt(d1*d1 - rr*rr);
    double s2 = sqrt(d2*d2 - rr*rr);
    double alpha1 = asin(rr/d1);
    double alpha2 = asin(rr/d2);
    double beta1 = arg(cr-l);
    double beta2 = arg(cr-d);
    complex<double> i (0,1);
    complex<double> f1 = l + s1*exp(i*(alpha1+beta1));
    complex<double> f2 = l + s1*exp(i*(beta1 - alpha1));
    complex<double> t1 = d + s2*exp(i*(alpha2+beta2));
    complex<double> t2 = d + s2*exp(i*(beta2 - alpha2));
    double circ = min(abs(arg(f1-cr)-arg(t2-cr))*rr, abs(arg(f2-cr)-arg(t1-cr)) *rr);
    printf("%.10f\n", s1+s2+circ);
}
