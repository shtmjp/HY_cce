#include <math.h>
#include <float.h>

/*
A modification of https://github.com/cran/yuima/blob/109b0e01febda3b694b8a7c2c16fbbcee22c312e/src/cce_functions.c#L222
*/

double HayashiYoshida(int xlength, int ylength, double *xtime, double *ytime, double *dX, double *dY)
{
    double value = 0.0;
    int I, J;
    I = 0;
    J = 0;

    /* Checking Starting Point */
    while ((I < (xlength - 1)) && (J < (ylength - 1)))
    {
        if (xtime[I] >= ytime[J + 1])
        {
            J++;
        }
        else if (xtime[I + 1] <= ytime[J])
        {
            I++;
        }
        else
        {
            break;
        }
    }

    /* Main Component */
    while ((I < (xlength - 1)) && (J < (ylength - 1)))
    {
        value += dX[I] * dY[J];
        if (xtime[I + 1] > ytime[J + 1])
        {
            J++;
        }
        else if (xtime[I + 1] < ytime[J + 1])
        {
            I++;
        }
        else
        {
            I++;
            J++;
        }
    }
    return value;
}

double PTRC(int xlength, int ylength, double *xtime, double *ytime, double *dX, double *dY)
{
    double value = 0.0;
    int I, J;
    I = 0;
    J = 0;

    /* Checking Starting Point */
    while ((I < (xlength - 1)) && (J < (ylength - 1)))
    {
        if (xtime[I] >= ytime[J + 1])
        {
            J++;
        }
        else if (xtime[I + 1] <= ytime[J])
        {
            I++;
        }
        else
        {
            break;
        }
    }

    /* Main Component */
    while ((I < (xlength - 1)) && (J < (ylength - 1)))
    {
        value += dX[I] * dY[J];
        if (xtime[I + 1] > ytime[J + 1])
        {
            J++;
        }
        else if (xtime[I + 1] < ytime[J + 1])
        {
            I++;
        }
        else
        {
            I++;
            J++;
        }
    }
    return value;
}
