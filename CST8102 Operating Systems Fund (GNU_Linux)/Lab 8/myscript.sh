#! /bin/bash
##############################################
# Nhi Banh
# cst8102 301
# lab 8
# script name: myscript.sh
# this script it a menu about user account
##############################################


valid=true

while [ $valid ]
do
	echo "Choose one of the following options:"
	echo "A) Create a user account"
	echo "B) Delete a user account"
	echo "C) Change supplementary group for a user account"
	echo "D) Change initial group for a user account"
	echo "E) Change default login shell for a user account"
	echo "F) Change account expiration date for a user account"
	echo "Q) Quit"

	echo "What would you like to do?: "
       	read choice


	################################
	# If A or a is chosen, the script should prompt you to enter the following information:
	# Username
	# User's home directory
	# Default login shell
	#Create the user account based on the information given above
	################################
	if [ $choice = "A" ] || [ $choice = "a" ]
	then
		read -p "Enter user name: " username
		read -p "Enter user's home directory: " homeDirectory
		read -p "Enter default login shell: " defaultLoginShell

		useradd -d $homeDirectory -m -s $defaultLoginShell $username
		cat /etc/passwd|grep $username

	################################
	# If B or b is chosen,
       	# it should prompt you for username of the account to be deleted,
       	# and delete the user account as well as the user's home directory.
	################################
	elif [ $choice = "B" ] || [ $choice = "b" ]
	then
		read -p "Enter user name: " username
		userdel -r $username


	################################
	# If C or c is chosen,
	# it should prompt you for username and group name that is added
	# as a supplementary group for the user account.
	################################
	elif [ $choice = "C" ] || [ $choice = "c" ]
	then
		read -p "Enter user name: " username
		read -p "Enter supplementary group for user account: " supgroup
		usermod -a -G $supgroup $username


	#################################
	# If D or d is chosen
	# It should prompt you for usename and group name
	# That is used as initial group for the user account
	# And change the initial group
	#################################
	elif [ $choice = "D" ] || [ $choice = "d" ]
	then
		read -p "Enter user name: " username
		read -p "Enter initial group for user account: " inigroup
		usermod -g $inigroup $username
		cat /etc/passwd|grep $username

	#################################
	# If E or e is chosen
	# It should prompt you for a username and shel name,
	# And change the default shell for the user account.
	#################################
	elif [ $choice = "E" ] || [ $choice = "e" ]
	then
		read -p "Enter user name: " username
		read -p "Enter default login shell for user account: " deflog
		usermod -s $deflog $username
		cat /etc/shells

	#################################
	# If F or f is chosen,
	# it should prompt you for username and expriration date,
	# And change the expiration date for the user account.
	#################################
	elif [ $choice = "F" ] || [ $choice = "f" ]
	then
		read -p "Enter user name: " username
		read -p "Enter account expiration date for a user account: " expdate
		chage -E $expdate $username

	##################################
	# If Q ir q is chosen,
	# the script should end
	##################################
	elif [ $choice = "Q" ] || [ $choice = "q" ] || [ $choice = "quit" ]
	then
		echo "Quitting"
		break

	else
	       echo "Invalid Option"

	fi # close if elif else

	##################################
	# It should sleep for 3 seconds after each menu
	##################################
	sleep 3


done # close while
