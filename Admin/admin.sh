#!/bin/bash
cd /home/always2k/Desktop/Scimail/Admin/
PASS="admin101"
read -s -p "Enter Admin Password: " mypassword
echo ""
if [ "$mypassword" == "$PASS" ]
then 
echo "Access Granted"
gcc -o admin admin.c
./admin
else
echo "Access Denied"
fi
