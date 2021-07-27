```sh
gem install specific_install --no-document
gem specific_install -l "git://github.com/himeyama/narray-fromfile.git"
./test.rb
od -t fD data.bin
gem uninstall narray-fromfile numo-narray
gem uninstall specific_install
```