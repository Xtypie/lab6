#include<iostream>
using namespace std;

int prost(int x)
{
    bool flag = true;
    for (int i = 2; i <= sqrt(x); i++) 
    {
        if (x % i == 0) 
        {
            flag = false;
        }
    }
    return flag;
}
int sumnum(int x)
{   
    x = abs(x);
    int sum = 0;
    while (x != 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
int multnum(int x)
{   
    x = abs(x);
    int mult = 1;
    while (x != 0)
    {
        mult *= (x % 10);
        x /= 10;
    }
    return mult;
}

void sort(int mas[], int const n)
{
    int timenum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < (n-1); j++)
        {
            if (mas[i] > mas[j])
            {
                timenum = mas[i];
                mas[i] = mas[j];
                mas[j] = timenum;

            }
        }
            
    }
}

void print(int mas[], int const n)
{
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main()
{   
    //ЗАДАНИЕ 1

   int n1;
   cin >> n1;
   int* msv = new int[n1];
   for (int i = 0; i < n1; i++)
   {
        cin >> msv[i];
   }
   print(msv, n1);
   int simplec = 0;
   for (int i = 0; i < n1; i++)
   {
        if (prost(msv[i]))
        {
            simplec++;
        }
   }

    if (simplec == 0)
    {
        sort(msv, n1 + 1 );
    }
    print(msv, n1); // Переделать сортировку



   
   



}