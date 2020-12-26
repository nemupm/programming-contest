## atcoder

### setup

```
brew install gcc
ln -s /usr/local/bin/$(ls /usr/local/bin/|grep g++-|head -n1) /usr/local/bin/g++
```

```
pip install atcoder-tools
```

### generate

```
atcoder-tools gen <contest_id> --workspace $HOME/src/github.com/nemupm/programming-contest/codes/ --template $HOME/src/github.com/nemupm/programming-contest/template.cpp
```

### compile, test, submit

[sanitizer doesn't work in macos with arm](https://github.com/google/sanitizers/wiki/AddressSanitizer)

```
g++ -O2 -I$HOME/src/github.com/nemupm/programming-contest/library/ac-library/ -DLOCAL -fsanitize=undefined,address ./main.cpp -o answer.exe
atcoder-tools test
atcoder-tools submit -u
```