#include <iostream>

using namespace std;

void switchOrientation(char &orientation, char a, char b, char c, char d){
    switch (orientation){
        case 'N': orientation=a; break;
        case 'S': orientation=b; break;
        case 'E': orientation=c; break;
        case 'W': orientation=d; break;
    }
}

int main() {
    int x0, y0, xn,yn;
    char orientation;
    bool lost=0;
    string direction;
    string::iterator itr;
    scanf("%d %d",&x0,&y0);
    bool *a1=new bool[2*(x0+y0+2)]; *a1={0};
    while(scanf("%d %d %c",&xn,&yn,&orientation)==3){
        cin>>direction;
        for(itr=direction.begin();itr!=direction.end() && !lost;++itr){
            switch (*itr){
                case 'F':
                    switch (orientation){
                        case 'N':
                            if(yn<y0) ++yn;
                            else if(yn==y0 && !a1[xn]) ++yn;
                            if(yn>y0) {if(xn==0) a1[2*(x0+y0)+3]=1;if(xn==x0) a1[x0+1]=1;a1[xn]=1;lost=1;--yn;}
                            break;
                        case 'S':
                            if(yn>0) --yn;
                            else if(yn==0 && !a1[2*x0+y0+2-xn]) --yn;
                            if(yn<0) {if(xn==0) a1[2*(x0+1)+y0+1]=1;if(xn==x0) a1[x0+y0+1]=1;a1[2*(x0+1)+y0+1-xn]=1;lost=1;++yn;}
                            break;
                        case 'E':
                            if(xn<x0) ++xn;
                            else if(xn==x0 && !a1[x0+y0+2-yn]) ++xn;
                            if(xn>x0) {if(yn==0) a1[x0+y0+2]=1;if(yn==y0) a1[x0]=1;a1[x0+y0+2-yn]=1;lost=1;--xn;};
                            break;
                        case 'W':
                            if(xn>0) --xn;
                            else if(xn==0 && !a1[2*x0+y0+3+yn]) --xn;
                            if(xn<0) {if(yn==0) a1[2*(x0+1)+y0]=1;if(yn==y0) a1[0]=1;a1[2*(x0+1)+y0+1+yn]=1;lost=1;++xn;}
                            break;
                    }
                    break;
                case 'R': switchOrientation(orientation,'E','W','S','N'); break;
                case 'L': switchOrientation(orientation,'W','E','N','S'); break;
            }
        }
        printf("%d %d %c", xn, yn, orientation);
        if(lost) printf(" LOST");
        printf("\n");
        lost=0;
    }
    return 0;
}
