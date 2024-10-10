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

void sort(int mas[], int const n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] > mas[j])
            {
                int tmp = mas[j];
                mas[i] = mas[j];
                mas[j] = tmp;
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
   bool flag = false;
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
        sort(msv, n1);
    }
    print(msv, n1);



   
   



}