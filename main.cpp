#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

int prost(int x) //проверка на простое число
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
int sumnum(int x) //сумма цифр числа
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
int multnum(int x) //произведение цифр числа
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

int povtor(int mas[], int const n) //проверка на наличие повтора в массиве
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

void sort(int mas[], int const n) //сортировка
{
    int timenum;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = i + 1; j < n; j++) // была замена (н-1) на н
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

void sortmult(int mas[], int const n) // сортировка по произведению цифр числа
{
    int timenum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < n; j++)
        {
            if ((sumnum(mas[i]) == sumnum(mas[j])) && (multnum(mas[i]) > multnum(mas[j])))
            {
                timenum = mas[i];
                mas[i] = mas[j];
                mas[j] = timenum;

            }
        }
            
    }
}



void print(int mas[], int const n) // вывод массива
{
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

bool cube(int n)
{
    int x = (int)pow((double)n, 1./3.);// вычислим кубический корень
    for(int t = x - 1; t<=x+1; t++) // из-за возможной ошибки округления переберем 3 соседних числа
        if(pow(t, 3) == n)
            return true;
    return false;
}
int main()
{   
    //ЗАДАНИЕ 1

   int n1;
   cout << "enter num of massive elements" << endl;
   cin >> n1;
   int* msv = new int[n1];
   cout << "enter elements of massive" << endl;
   for (int i = 0; i < n1; i++) {cin >> msv[i];}

   print(msv, n1);
   int simplec = 0;
   for (int i = 0; i < n1 - 1; i++) {if (prost(msv[i])) {simplec++;}}

   if (simplec == 0) {sort(msv, n1); print(msv, n1);}
   else{cout << "simple nums in massive" << endl;} 
   
   delete[] msv;


    //ЗАДАНИЕ 2

    int n2;
    cout << "enter num of massive elements" << endl;
    cin >> n2;
    int* msv2 = new int[n2];
    int* msvsum = new int[n2]; //массив с суммами цифр числа
    int* msvmult = new int[n2]; //массив с проезвидением цифр числа
    cout << "enter massive elements" << endl;
    for (int i = 0; i < n2; i++) {cin >> msv2[i];}
    for (int i = 0; i < n2; i++) {msvsum[i] = sumnum(msv2[i]); msvmult[i] = multnum(msv2[i]);}
    sort(msvsum, n2);
    sortsum(msv2, msvsum, n2);
    if (!povtor(msvsum, n2)){sortsum(msv2, msvsum, n2);}
    else if (povtor (msvsum, n2)){sortmult(msv2, n2);}
    else if ((povtor(msvsum, n2)) && (povtor(msvmult, n2))) {sort(msv2, n2);}
    print(msv2, n2);
    delete[] msv2, msvsum, msvmult;

    // ЗАДАНИЕ 3

    int row, col, k, mx, str;
    k = 1;
    mx = 0;
    str = 0;
    cout << "enter row and col" << endl;
    cin >> row >> col;
    int matr[100][100];
    cout << "enter matrice elements" << endl;
    for (int i = 0; i < row; i++)
    {
        if (k > mx){mx = k; str = i;}
        k = 1;
        for (int j = 0; j < col; j++){cin >> matr[i][j]; k *= matr[i][j];}
    }
    for (int j = 0; j < col; j++) {matr[(str-1)][j] = mx;} //замена элементов строки на максимальное произведение

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {cout << matr[i][j] << " ";}
        cout << endl;
    }
    
    //ЗАДАНИЕ 4

    const int size4 = 20001;
    int msv4[size4], n4;
    cout << "enter num of massive elements" << endl;
    cin >> n4;
    int t = 0;
    for (int i = 0 ; i < n4 ; i++) {msv4[i] = i + 1;}// cin >> msv4[i];
    print(msv4, n4);
    for (int i = 0; i < n4; i++)
    {
        if ((prost(msv4[i]))){continue;}
        msv4[t] = msv4[i];
        t++;
    }
    n4 = t;
    print(msv4, n4);
    for (int i = 0; i < n4; i++)
    {   if (cube(msv4[i]))
        {
            for (int j = n4; j > i; j--)
            {
                msv4[j] = msv4[j-1];
            }
            i++;
            n4++;
        }
        
    }
    print(msv4, n4);
    // УРА ПОБЕДА!!!
}