from Cython.Build import cythonize
from setuptools import Extension, setup

DEBUG = True

if DEBUG:
    opt_level = "-O0"
else:
    opt_level = "-O3"

ext = Extension(
    name="c_lib",
    sources=["c_lib.pyx", "hy.c"],
    extra_compile_args=[opt_level],  # -03: 最適化レベル
    extra_link_args=[opt_level],
)

setup(name="my hy module", ext_modules=cythonize([ext]))

# 以下のコマンドを実行してビルドする
# python3 setup.py build_ext --inplace
