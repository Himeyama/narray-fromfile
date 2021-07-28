# narray-fromfile

[![build](https://github.com/Himeyama/narray-fromfile/actions/workflows/build.yml/badge.svg)](https://github.com/Himeyama/narray-fromfile/actions/workflows/build.yml) [![Gem Version](https://badge.fury.io/rb/narray-fromfile.svg)](https://badge.fury.io/rb/narray-fromfile)

## 概要
倍精度浮動小数点のバイナリファイルを NArray 行列として読み(書き)します。

**単精度浮動小数点** は対応していません。

## インストール

```sh
gem install narray-fromfile
```

---

GitHub から、`narray-fromfile` をインストールするには以下のコマンドを実行します。
```sh
gem install specific_install
gem specific_install -l "git://github.com/himeyama/narray-fromfile.git"
```


### Gemfile に記述する場合は以下のように

```sh
gem "narray-fromfile"
```

---

GitHub からインストールしたい場合は、

```rb
gem "narray-fromfile", github: "himeyama/narray-fromfile.git", branch: :main
```

## サンプル

### 書き込み
```rb
require "numo/narray"
require "fromfile"

a = Numo::DFloat[1..256].reshape(16, 16)
a.tofile("data.bin")
```

### 読み込み
```rb
require "numo/narray"
require "fromfile"

a = Numo::DFloat.fromfile("data.bin").reshape(16, 16)
# 行と列のサイズは保存されないので、読み込み後 reshape する。
```

### 確認
```sh
od -t fD data.bin
```
