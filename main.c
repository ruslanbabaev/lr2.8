#include <stdio.h>
 
//Зададим программно функцию x^3-2x^2+3
double func(double x)
{
    return x*x*x - 2*x*x + 3;
}

 
double dichotomy(double a, double b, double exp)
{
    double x;
    if(func(a) * func(b) >= 0)
    {
        printf("Границы интервала заданы неверно\n");
        return 0;
    }
 
    x = a;
 
    while ((b-a) >= exp)
    {
        x = (a+b)/2;
        if (func(x) == 0.0){
            //printf("Корень = %lf\n",x);
            break;
        }
        else if (func(x)*func(a) < 0){
                //printf("Корень = %lf\n",x);
                b = x;
        }
        else{
                //printf("Корень = %lf\n",x);
                a = x;
        }
    }
    return x;
}
 
int main()
{
    double a = 0.0, b = 0.0, eps = 0.0;
    printf("Введите границы интервала: ");
    scanf("%lf %lf", &a, &b);
    printf("\n");
    printf("Введите точность: ");
    scanf("%lf", &eps);
    printf("\n");
    printf("Решение функции x^3-2x^2+3\n");
    printf("a = %lf\n", a);
    printf("b = %lf\n", b);
    
    printf("Самое близкое значение = %lf\n", dichotomy(a,b, eps));
 
    return 0;
}
