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
        for (int j = i ; j < n; j++) // была замена (н-1) на н
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

void sortmult(int mas[], int masmult[], int const n) // сортировка по произведению цифр числа
{
    int timenum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            if (masmult[i] == multnum(mas[j]))
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

   /*int n1;
   cin >> n1;
   int* msv = new int[n1];
   for (int i = 0; i < n1; i++) {cin >> msv[i];}

   print(msv, n1);
   int simplec = 0;
   for (int i = 0; i < n1 - 1; i++) {if (prost(msv[i])) {simplec++;}}

   if (simplec == 0) {sort(msv, n1); print(msv, n1);}
   else{cout << "simple nums in massive" << endl;} */


    //ЗАДАНИЕ 2

    /*int n2;
    cin >> n2;
    int* msv2 = new int[n2];
    int* msvsum = new int[n2]; //массив с суммами цифр числа
    int* msvmult = new int[n2]; //массив с проезвидением цифр числа

    for (int i = 0; i < n2; i++) {cin >> msv2[i];}
    for (int i = 0; i < n2; i++) {msvsum[i] = sumnum(msv2[i]); msvmult[i] = multnum(msv2[i]);}
    sort(msvsum, n2);
    sort(msvmult, n2);
    if (povtor(msvsum, n2))
    {
        sortmult(msv2, msvmult, n2);
    }
    else if (!povtor(msvsum, n2))
    {
        sort(msvsum, n2);
        sortsum(msv2, msvsum, n2); //сортировка по сумме цифр числа
    }
    else if (povtor(msvmult, n2))
    {
        sort(msv2, n2);
    }
    print(msv2, n2);*/

    // ЗАДАНИЕ 3

    int row, col, k, mx, str;
    k = 1;
    mx = 0;
    str = 0;
    cin >> row >> col;
    int matr[20][20];
    for (int i = 0; i < row; i++)
    {
        if (k > mx){mx = k; str = i;}
        k = 1;
        for (int j = 0; j < col; j++){cin >> matr[i][j]; k *= matr[i][j];}

    }
    
    for (int i = 0; i < row; i ++)
    {
        if (i = (str - 1))
        {
            for (int j = 0; j < col; j++) {matr[i][j] = mx;}
            break;
        }

    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    



    
    


   
   



}