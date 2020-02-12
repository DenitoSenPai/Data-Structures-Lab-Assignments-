#include <iostream>

using namespace std;

/*
    Dinito Thompson : 180202
    I was getting an error saying that "Class wasnt a specific datatype." when I was trying to implement MathLib. 
*/
class IterativeMathLib
{
private:
    int x, y, n;
public :
    int GCD(int x, int y)
    {
        while (x != 0)
        {
            x = x % y;
        }
        return x;;
    }

    int FIB(int x)
    {
        while (x != 0 || x != 1)
        {
            x = (x - 1) + (x - 2);
        }
        return x;
    }

    int Hanoi(int n)
    {
        while (n != 1 && n > 1)
        {
            n = 2 * (n - 1) + 1;
        }
        return n;
    }
}
;

class RecursiveMathLib
{
private :
    int x, y, n;
public :

    int GCD(int x, int y)
    {
        if (x == 0)
        {
            return x;
        }
        else if (x >= 0 && x != 0)
        {
            x = GCD(y, x % y);
        }
    }
    /*
    int FIB(int x)
    {
    if (x == 0)
    {
        return x;
    }
    if (x == 1)
    {
        return x;
    }
    if (x > 1)
    {
        x = Fib(x - 1) + Fib(x - 2);
    }
    }
    */
    int Hanoi(int n)
    {
        if (n = 1)
        {
            return n;
        }
        else if (n > 1)
        {
            n = 2 * Hanoi(n - 1) + 1;
        }
    }
}
;

int main()
{
    RecursiveMathLib R;
    IterativeMathLib I;

    cout << "Recursive GCD of 2 and 100: " << R.GCD(2, 100) << endl;
    cout << "Recursive Hanoi of 50: " << R.Hanoi(50) << endl;

    cout << "Iterative GCD of 500 and 1000: " << I.GCD(500, 100) << endl;
    cout << "Iterative Fib of 50: " << I.FIB(50) << endl;
    cout << "Iterative Hanoi of 100: " << I.Hanoi(100) << endl;
    return 0;
}
