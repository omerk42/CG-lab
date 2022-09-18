# CG-lab
# HOW TO use 

1- u should see Fork button upside of the repo \
just click in it :) \
then create fork \
2- u should see clone of repo but in ur acc \
clone it via ssh or http

**u should set ssh key in ur device** 
if u dont [click here](#set-ssh)



> git clone <url of repo> \
> cd <cloned folder name> \
3- u shold see folders with labs name \
> cd <lab folder> \
4- add ur c++ code here name it like this ( lab<lab num>_<ur stu id> ) \
5- now add ur file in git \
> git add <ur file name> \
```diff
- please add only ur c++ file do not use git add . 
``` \
> git commit -m "< ur stu id> <lab num>" \
> git push \
6- now from github click on Pull request -> New pull request \
Next next .. ;) \

## Set Ssh

1 - create ssh key \
 > ssh-keygen -t ed25519 -C "ur email" \
 // will ask to enter key passphrase (optinal can be empty) \
 // note that enter it will require u to re enter it for every clone,pull,push \
2 - copy whole genrated ssh key \
 // or \
 > xclip -sel clip < ~/.ssh/id_ed25519.pub // need to install xclip \ 

3 - add it to git lab same for github \
 // prefrence -> SSH Keys -> past whole key in key box \

4 - verify \
 > ssh -T git@gihub.com \
 // will show M about key fingerprint (type yes) \
 // enter ur key passphrase if u made one \
 // answe should be \
 // Hi <ur user>! You've successfully authenticated, but GitHub does not provide shell access. \
5 - config email,user \

 > git config --global user.email "ur email" \
 > git config --global user.user "ur username" \
