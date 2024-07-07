# HY_cce
Hayashi-Yoshida共分散推定量の数値実験

## How to set up

```
pyenv local 3.11.2 \
&& pipenv --python 3.11.2 \
&& pipenv shell \
&& pipenv install
```

flake8等のdev-packagesがないときは

```
pipenv install --dev
```

`src/hy`に移動してCライブラリをビルド
```
python3 setup.py build_ext --inplace
```

