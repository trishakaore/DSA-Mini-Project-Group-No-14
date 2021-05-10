                                                           **BITCOIN**

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

Our implementation accomodates the following functions among others that go on behind the scenes:

1. View list of users and their details
2. Perform transactions
3. View the blockchain 
4. View a certain user's transaction history
5. Attempt an attack (this will change the nonce)
6. Validate the blockchain - detect an attack and undo it by restoring the nonce value
7. Storage and retrieval of the user database and the blockchain from files to allow for backup even after the program excecution has ended

Each block in the block chain conists of 50 transactions.

The hash values of the blocks are calculated using the parameters - transactions, block number and nonce.

We have written the hash function ourselves and tested it extensively to conclude that it is void of duplication, and serves our purposes.

Our project also accomodates storage of users and the block chain in files. These can be used to backup data.
Implementation is done through file handling, and lends itself to easily dealing with large amounts of users and transactions.

                                                   **Running the program**

1. For the testcases we have set number of users to be created to 100 and number of transactions to 1250. If you wish to change these values then
   - Open ```create_users.c```, and change UserNum to the number of users required. The program can handle 9000 users at max, but we recommend not exceeding 5000 to ensure smoother functioning.
   - Open ```create_transactions.c```, change TranNum to required number of transactions such that 2*TranNum/UserNum < 60 
2. Run ```make project```. This loads randomly generated users and performs transactions with these users from ```create_users.c``` and ```create_transactions.c``` into the backup files.

3. You may now run ```./main```
4. Enter 'y' to load all the data that was just generated into the program
5. Now all the other functions may be used as required. New users may be added manually. Do not use the createusers.c, or the previous data will be wiped.
6. Similarly transactions may also be performed.
7. To save changes to files when exiting, enter 'y' again when prompted. If 'y' is not entered then all the transactions made and users added in that run of the program will not be saved to files.

                                                              Thank You
