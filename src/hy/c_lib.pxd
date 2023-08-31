cdef extern from "hy.h":
    double HayashiYoshida(int xlength, int ylength, double *xtime, double *ytime, double *dX, double *dY)
