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

```
g++ -o answer.exe main.cpp
atcoder-tools test
atcoder-tools submit -u
```