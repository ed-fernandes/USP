#include <stdio.h>
long long int p(long long int a,long long int b,long long int c,long long int d){
   return printf("HIT: %lld %lld %lld %lld",a,b,c,d);
}
int main(void) {
    long long int x1,y1,l1,a1,x2,y2,l2,a2;
    scanf("%lld %lld %lld %lld\n%lld %lld %lld %lld", &x1,&y1,&l1,&a1,&x2,&y2,&l2,&a2);
    if(x2 >= x1 && x2 <= x1+l1){
        if(y2 > y1+a1 || y2+a2 < y1){
            printf("MISS");    
        }else if(y2 >= y1 && y2 <= y1+a1){
            if(x2+l2 <= x1+l1 && y2+a2 <= y1+a1){
                p(x2,y2,l2,a2);
            }else if(x2+l2 >= x1+l1 && y2+a2 >= y1+a1){
                p(x2,y2,l1-x2+x1,a1-y2+y1);
            }else if(x2+l2 <= x1+l1 && y2+a2 >= y1+a1){
                p(x2,y2,l2,a1-y2+y1);
            }else if(x2+l2 >= x1+l1 && y2+a2 <= y1+a1){
                p(x2,y2,l1-x2+x1,a2);
            }
        }else if(y2 <= y1 && y1 <= y2+a2){
            if(x2+l2 <= x1+l1 && y2+a2 <= y1+a1){
                p(x2,y1,l2,a2-y1+y2);
            }else if(x2+l2 >= x1+l1 && y2+a2 >= y1+a1){
                p(x2,y1,l1-x2+x1,a1);
            }else if(x2+l2 <= x1+l1 && y2+a2 >= y1+a1){
                p(x2,y1,l2,a1);
            }else if(x2+l2 >= x1+l1 && y2+a2 <= y1+a1){
                p(x2,y1,l1-x2+x1,a2-y1+y2);
            }
        }else{
             p(x2,y2,l1-x2+x1,0);
        }
    }else if(x2 <= x1 && x1 <= x2+l2){
        if(y2 > y1+a1 || y2+a2 < y1){
            printf("MISS");    
        }else if(y2 <= y1 && y1 <= y2+a2){
            if(x2+l2 <= x1+l1 && y2+a2 <= y1+a1){
                p(x1,y1,l2-x1+x2,a2-y1+y2);
            }else if(x2+l2 >= x1+l1 && y2+a2 <= y1+a1){
                p(x1,y1,l1,a2-y1+y2);
            }else if(x2+l2 >= x1+l1 && y2+a2 >= y1+a1){
                p(x1,y1,l1,a1);
            }else if(x2+l2 <= x1+l1 && y2+a2 >= y1+a1){
                p(x1,y1,l2-x1+x2,a1);
            }
        }else if(y2 >= y1 && y2 <= y1+a1){
            if(x2+l2 <= x1+l1 && y2+a2 <= y1+a1){
                p(x1,y2,l2-x1+x2,a2);
            }else if(x2+l2 >= x1+l1 && y2+a2 <= y1+a1){
                p(x1,y2,l1,a2);
            }else if(x2+l2 >= x1+l1 && y2+a2 >= y1+a1){
                p(x1,y2,l1,a1-y2+y1);
            }else if(x2+l2 <= x1+l1 && y2+a2 >= y1+a1){
                p(x1,y2,l2-x1+x2,a1-y2+y1);
            }
        }else {
            p(x1,y1,0,a2-y1+y2);
        }
    }else{
        printf("MISS");
    }
}