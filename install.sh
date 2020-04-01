#!/bin/bash
sudo apt-get install postfix
sudo postconf -e 'home_mailbox= Maildir/'
sudo ufw allow Postfix
##to restart postfix
sudo postfix reload
sudo apt-get install mailutils
#echo "alias scimail='/home/always2k/Desktop/Scimail/script.sh ./script.sh'" >> ~/.bash_aliases
#echo "alias scimail-admin='/home/always2k/Desktop/Scimail/Admin/admin.sh ./admin.sh'" >> ~/.bash_aliases
#source ~/.bash_aliases
