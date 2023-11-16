//
// Created by reprise on 2023/11/12.
//
#include <stdio.h>
#include <math.h>
int n,p;
int nums[25];
double f (double x) {
    double t = 0;
    for (int i = n; i >= 0; i--) {
        t = t * x + nums[i];
    }
    return pow (t,p);
}
double S (double a,double b) {
    double mid = (a + b) / 2;
    double ret = (4 * f(mid) + f(a) + f(b)) * (b - a) / 6;
    return ret;
}
double Solve (double a,double b,double e) {
    double mid = (a + b) / 2;
    double SL = S(a,mid);
    double SR = S(mid,b);
    double SA = S(a,b);
    if (fabs(SL + SR - SA) <= 15 * e) {
        return SL + SR + (SL + SR - SA) / 15;
    }
    return Solve(a,mid,e / 2) + Solve (mid,b,e / 2);
}

int main() {
    double e = 1e-4;
    double a,b;
    scanf("%d%d",&n,&p);
    for (int i = 0; i <= n; i++) {
        scanf("%d",&nums[i]);
    }
    scanf("%lf%lf",&a,&b);

    printf("%f", Solve(a,b,e));
    return 0;
}