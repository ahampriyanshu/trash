### Installation in Ubuntu(debian)

* curl or wget the tar.gz file\ 
``curl -O https://storage.googleapis.com/golang/go1.12.9.linux-amd64.tar.gz``

* Extract\
``tar -xvf go1.12.9.linux-amd64.tar.gz``

* Adjust the permissions and move the go directory to /usr/local:
```bash
sudo chown -R root:root ./go
sudo mv go /usr/local
```

* Open ~/.profile file and add the following two lines to the bottom of the file to adjust Path and Root:

```bash
nano ~/.profile
export GOPATH=$HOME/go
export PATH=$PATH:/usr/local/go/bin:$GOPATH/bin
```
* Save the file,and execute\
``source ~/.profile``

* To verify installation is successfull run\
``go version``