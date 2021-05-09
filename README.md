                                                         BITCOIN

Ananya Sane             
2020102007

Trisha Kaore            
2020111021

M Krishna Praneet       
2020113010

G Vinaychandra Reddy    
2020101010

B Vishwateja Reddy      
2020102058



This project is an implementation of a blockchain. Although it is simplified, it still retains the core ideas of block hash values, privacy, validation and attack detection and mitigation.

Our implementation accomodates the following functions:

1. View list of users and their details
2. Perform transactions
3. View the blockchain 
4. View a certain user's transaction history
5. Attempt an attack (this will change the nonce)
6. Validate the blockchain - detect an attack and undo it by restoring the nonce value
7. Storage and retrieval of the user database and the blockchain from files to allow for backup even after the program excecution has ended.

among others that go on behind the scenes.

Each block in the block chain conists of 50 transactions.

The hash values of the blocks are calculated using the parameters - transactions, block number and nonce.

We have written the hash function ourselves and tested it extensively to conclude that it is void of duplication, and for our purposes.

Our project also accomodates storage of users and the block chain in files. These can be used as to backup data.
Implementation is done through file handling, and lends itself to easily dealing with large amounts of users and transactions.

                                           Running the program:

1. Open create_users.c, and change UserNum to the number of users required.
2. Run gcc create_users.c -o create_users
3. Run ./create_users > input_users.txt
4. Run gcc main.c -o main to compile the main program.
5. Run ./main < input_users.txt

6. Open create_transactions.c, change TranNum to required number of transactions such that 2*TranNum/UserNum < 60 
7. Run gcc create_transactions.c -o create_transactions
8. Run ./create_transactions > input_transactions.txt
9. Run ./main < input_transactions.txt

10. You may now run ./main
11. Enter 'y' to load all the data that was just generated into the program
12. Now all the other functions may be used as required.
13. To save changes to files when exiting, enter 'y' again when prompted. If 'y' is not entered then all the transactions made and users added in that run of the program will not be saved to files.

                                              Thank You
