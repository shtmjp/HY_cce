import numpy as np
cimport c_lib

def hy(data1, data2):
    tx, x = data1
    ty, y = data2
    assert len(tx) == len(x)
    assert len(ty) == len(y)

    dx, dy = np.diff(x), np.diff(y)

    # 配列の要素がメモリ上連続して並ぶことを保証する
    for arr in [tx, ty, dx, dy]:
        if not arr.flags['C_CONTIGUOUS']:
            arr = np.ascontiguousarray(arr)

    cdef double[::1] tx_m = tx
    cdef double[::1] ty_m = ty
    cdef double[::1] dx_m = dx
    cdef double[::1] dy_m = dy
    cdef xlength = len(x)
    cdef ylength = len(y)

    return c_lib.HayashiYoshida(xlength, ylength, &tx_m[0], &ty_m[0], &dx_m[0], &dy_m[0])






