CC = gcc
CFLAGS = -g

project: create_users.c main.c create_transactions.c 
		 gcc create_users.c -o create_users
		 ./create_users > input_users.txt
		 gcc main.c -o main
		 ./main < input_users.txt
		 gcc create_transactions.c -o create_transactions
		 ./create_transactions > input_transactions.txt
		 ./main < input_transactions.txt