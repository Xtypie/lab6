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

int povtor(int mas[], int const n)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            if (mas[i] = mas[j]){flag = true;}
        }
    }
    return flag;
}

void sort(int mas[], int const n)
{
    int timenum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < n; j++)
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

void sortsum(int mas[], int massum[], int const n) // сортировка по сумме цифр числа
{
    int timenum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            if (massum[i] == sumnum(mas[j]) )
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
   for (int i = 0; i < n1; i++) {cin >> msv[i];}

   print(msv, n1);
   int simplec = 0;
   for (int i = 0; i < n1; i++) {if (prost(msv[i])) {simplec++;}}

    if (simplec == 0) {sort(msv, n1 + 1 );}

    print(msv, n1);

    //ЗАДАНИЕ 2

    int n2;
    cin >> n2;
    int* msv2 = new int[n2];
    int* msvsum = new int[n2]; //массив с суммами цифр числа
    int* msvmult = new int[n2]; //массив с проезвидением цифр числа

    for (int i = 0; i < n2; i++) {cin >> msv2[i];}
    for (int i = 0; i < n2; i++) {msvsum[i] = sumnum(msv2[i]); msvmult[i] = multnum(msv2[i]);}
    sort(msvsum, n2);
    sortsum(msv2, msvsum, n2); //сортировка по сумме цифр числа
    print(msvsum, n2);
    print(msv2, n2);
    /*if (povtor(msvsum, n2))
    {

    }
    else
    {
        sort(msvsum, n2);
        sortsum(msv, msvsum, n2); //сортировка по сумме цифр числа
        print(msv, n2);
    }
    */
    


   
   



}