#include <iostream>
using namespace std;
double n, ans;

double pow3(double num)
{
    return num * num * num;
}

int main()
{
    cin >> n;
    double left = -100000000, right = 100000000;
    double mid;
    for (int i = 0; i < 1000; i++)
    {
        mid = (left + right) / 2;
        if (pow3(mid) < n)
            left = mid;
        else
            right = mid;
    }
    printf("%.6f", mid);
    return 0;
}