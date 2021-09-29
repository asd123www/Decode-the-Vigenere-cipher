#include <bits/stdc++.h>


#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,l,r) for(int i=l;i>=r;--i)


typedef long long s64;
typedef unsigned long long ull;

int sum(int *a, int l, int r) {
    int ans=0;
    rep(i,l,r) ans+=*(a+i);
    return ans;
}

/* a 是我自己计算出来的alpha bet frequency.
 * b 是 ground truth.
 * b 永远不偏移.
 */
double distance(int *a, int *b, int l=0) { 
    double sum_a = sum(a, 0, 25);
    double sum_b = sum(b, 0, 25);
    double ans=0;
    rep(i,0,25) ans+=abs(a[i+l]/sum_a-b[i]/sum_b);
    return ans;
}

void init(int *alpha_f) {
    alpha_f['A'-'A']= 14810,
    alpha_f['B'-'A']= 2715,
    alpha_f['C'-'A']= 4943,
    alpha_f['D'-'A']= 7874,
    alpha_f['E'-'A']= 21912,
    alpha_f['F'-'A']= 4200,
    alpha_f['G'-'A']= 3693,
    alpha_f['H'-'A']= 10795,
    alpha_f['I'-'A']= 13318,
    alpha_f['J'-'A']= 188,
    alpha_f['K'-'A']= 1257,
    alpha_f['L'-'A']= 7253,
    alpha_f['M'-'A']= 4761,
    alpha_f['N'-'A']= 12666,
    alpha_f['O'-'A']= 14003,
    alpha_f['P'-'A']= 3316,
    alpha_f['Q'-'A']= 205,
    alpha_f['R'-'A']= 10977,
    alpha_f['S'-'A']= 11450,
    alpha_f['T'-'A']= 16587,
    alpha_f['U'-'A']= 5246,
    alpha_f['V'-'A']= 2019,
    alpha_f['W'-'A']= 3819,
    alpha_f['X'-'A']= 315,
    alpha_f['Y'-'A']= 3853,
    alpha_f['Z'-'A']= 128;


    rep(i,26,51) alpha_f[i]=alpha_f[i-26];
}
