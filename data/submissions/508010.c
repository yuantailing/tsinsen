#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a>0)
        printf("%.2lf %.2lf",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
    else
        printf("%.2lf %.2lf",(-b-sqrt(b*b-4*a*c))/(2*a),(-b+sqrt(b*b-4*a*c))/(2*a));
    return(0);
}
