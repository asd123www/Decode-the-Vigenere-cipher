#include <bits/stdc++.h>
#include "init.h"

const int M=1e2+5;

int n;
int buc[30][30];
double val[30];
int rank[30][30];
char s[M];
int f[M];
int decipher[M];
int alpha_f[30];


bool comp(int x,int y) {return val[x] < val[y];}

void get_buc(int x, int len) {
    int now = x;
    memset(buc[x],0,sizeof(buc[x]));
    while (now<=n) {
        ++ buc[x][s[now]-'A'];
        now+=len;
    }

    rep(i,26,51) buc[x][i]=buc[x][i-26];
    rep(i,0,25) rank[x][i]=i;
    rep(i,0,25) val[i]=distance(buc[x], alpha_f, i);
    std::sort(rank[x], rank[x]+26, comp);
    
    //rep(i,0,25) std::cout<<rank[x][i]<<" ";
    //std::cout<<std::endl;
}

int choose[M], total[M];

void print(int len) {
    int be=1;

    puts("key: ");
    rep(i,1,len) putchar(choose[i]+'a'); puts("");

    rep(i,1,n) {
        putchar((s[i]-'A'-choose[be]+26)%26+'a');

        ++be;
        if(be>len) be=1;
    }
    puts("");
    puts("");
}

void check(int len) {
    memset(total,0,sizeof(total));
    rep(j,1,len) rep(i,0,25) 
        total[i] += buc[j][choose[j] + i];
    //rep(i,1,len) std::cout<<choose[i]<<" "; puts("");
    //std::cout<< distance(total, alpha_f)<<std::endl;puts("");
    if(distance(total, alpha_f) < 0.4) print(len); 
}

void dfs(int x,int len) {
    if(x==len+1) return check(len),void();

    rep(i,0,1) {
        choose[x] = rank[x][i];
        dfs(x+1,len);
    }
}

void solve(int len) {
    rep(i,1,len) get_buc(i, len);
    dfs(1,len);
}

signed main() {
    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);


    init(alpha_f);


    solve(7);
    //rep(i,1,8) solve(i);
}

/*

key: 
havefun
cryptographyhasgonefromaheuristicsetoftoolsconcernedwithensuringsecretcommunicationforthemilitarytoasciencethathelpssecuresystemsforordinarypeopleallacrosstheglobethisalsomeansthatcryptographyhasbecomeamorecentraltopicwithincomputerscience

*/