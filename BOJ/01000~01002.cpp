#include <stdio.h>
#include <iostream>

using namespace std;

int main_01000(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", a+b);

    return 0;
}

// ###########################################

int main_01001(){
    ios::sync_with_stdio(false);    cin.tie(0);
    int a,b;
    cin >> a >> b;
    cout << a-b;
}

// ###########################################

int TC;
int x1, y1, x2, y2;
int r1, r2;

int main_01002(){
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
        int d_square = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        int R_square = (r1+r2) * (r1+r2);
        int r_square = (r1-r2) * (r1-r2);
        if(x1==x2 && y1==y2 && r1==r2)
            puts("-1");
        else if(d_square > R_square || d_square < r_square)
            puts("0");
        else if(d_square==R_square || d_square==r_square)
            puts("1");
        else 
            puts("2");
    }
    return 0;
}