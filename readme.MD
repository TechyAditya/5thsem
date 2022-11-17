# 5th Sem Labs
# CN Notes
## UDP
Server
1. Create socket and save it's file descriptor - 
socket(AF_INET, SOCK_DGRAM, 0)
2. Error check socket
3. memset addresses to 0
4. Set IP and port of server address
5. Bind socket to server address -  
bind(sockfd, &servaddr, size)
6. Error check bind

Connection complete

Receive data: recvfrom(sockfd, data, size, 0, &cliaddr, sizeof(cliaddr))

Send data: sendto(sockfd, data, size, 0, &cliaddr, sizeof(cliaddr))

Client
1. Create socket and error control
2. memset server and set IP and port to it

Connection complete

## TCP
Server
1. Create TCP socket - 
socket(AF_INET, SOCK_STREAM, 0)
2. Error control socket
3. memset and set IP and port to servaddr
4. Bind the socket - 
bind(sockfd, &servaddr, size)
5. Error control bind
6. Error control listen test
7. Accept client connection and set it to file descriptor - 
accept(sockfd, &cliaddr, len)
8. Error check incoming connections

Connection complete

Receive data: recv(sockfd, data, size, 0)

Send data: send(connfd, data, size, 0) 

Client
1. Create socket and error check
2. memset and set IP and port to INADDR_ANY and any number
3. connect to server using socket - 
connect(sockfd, &servaddr, size)

Connection complete



# DAA
[**Lab 1**](DAA/lab1)

WAP to find the frequency of numbers in an array

WAP to implement Bubble Sort. Take 3 different set of input. For each of the case count the number of comparission to reach final array.

[**Lab 2**](DAA/lab2)

Rearrange n elements into odd and even

Test if n is prime

Swap pairs of elements of array

[**Lab 3**](DAA/lab3)

Insertion Sort with number of steps

Insertion Sort with time-taken

[**Lab 4**](DAA/lab4)

Let A be a list of n (not necessarily distinct) integers. Write a program by using User Defined Function(UDF)s to test whether any item occurs more than n/2 times in A.

Implement Binary Search algorithm using divide and conquer technique

[**Lab 5**](DAA/lab5)

Write a program by using an user defined function for computing √n for any positive integer n

Implement sets

Find max value of Si-j in O(n2) time

[**Lab 6**](DAA/lab6)

Merge sort

Exponential Problem

[**Lab 7**](DAA/lab7)

Max-Heap

Min-Heap

[**Lab 8**](DAA/lab8)

**Extra class**

Implement Fractional Knapsack Problem

Activity Selection Problem

Huffman Coding

[**Lab 9**](DAA/lab9)

Implement 0/1 Knapsack Problem

Activity Selection Problem with all possibilities of largest actions

[**Lab 10**](DAA/lab10)

Longest Common Subsequence

Matrix Chain Multiplication