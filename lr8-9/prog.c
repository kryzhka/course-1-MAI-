#include <stdio.h>
int abs(int number)
{
    if(number>=0)
    return number;
    return -number;
}
int sign(int number)
{
    if(number>0)
    return 1;
    else if(number=0)
    return 0;
    return -1;
}
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int paw(int a)
{
    return a*a;
}
int main()
{
    const int i0 = 5, j0 = 5, l0 = 4, x1 = -10, y1 = -10, x2 = -20, y2 = -20, r = 10;
    int i = i0, j = j0, l = l0, k = 0, i_n, j_n, l_n;
    while(k < 50)
    {
        i_n=i/3-abs(i-k)*sign(l-j);
        j_n=j%10-max(i,l)%(k+1);
        l_n=i+j*k%5+l/5+3;
        ++k;
        //printf("%d%s%d%s%d\n",k," ",i_n," ",j_n); Отладочная часть
        if(paw(i_n-x1)+paw(j_n-y1)<paw(r)&&paw(i_n-x2)+paw(j_n-y2)<paw(r))
        {
            printf("%s\n","Попадание в заданную область не более чем за 50 шагов");
            printf("%s%d\n%s%d\n","Время окончания движения: ",k,"Значение динамического параметра движения: ",l_n);
            printf("%s%d%s%d\n","Конечные координаты точки: i= ",i_n," j=",j_n);
            return 0;
        }
        i=i_n;
        j=j_n;
        l=l_n;
    }
    printf("%s\n","Промах");
    printf("%s%d\n%s%d\n","Время окончания движения: ",k,"Значение динамического параметра движения: ",l_n);
    printf("%s%d%s%d\n","Конечные координаты точки: i= ",i_n," j=",j_n);

    return 0;
}