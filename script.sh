#! /bin/bash
var=`ps aux | grep [p]ostfix | wc -l`
if [ $var == 0 ]
then 
	echo -e "======================"
	echo "POSTFIX IS NOT RUNNING"
	echo -e "======================\n"
else
	echo "=================="
	echo "POSTFIX IS RUNNING"
	echo "Running java client"
	cd ~/Desktop/Scimail/
	javac -d . RunningSS.java
	javac -d . Client_Page.java
	java shellwrapper.Client_Page
	#echo "Filtering Mail"
	gcc -o execute executioner.c
	./execute
	echo "Mail Sent"
	cd /home/always2k/Desktop/Scimail/Admin/Logs/
	touch log.txt
	cd /var/log
	grep -e 'uid' -e 'from' -e 'to' -e 'message-id'  mail.log | tail -n 4 >> /home/always2k/Desktop/Scimail/Admin/Logs/log.txt
fi




