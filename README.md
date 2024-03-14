# CS2001-project
FAST NUCES || CS2001 Data Structures || Semester 3 Project
1.The user should be able to control and track the movement of the cursor.
2.The user can access, add and delete any part of the text.
3.To add or delete a text, the user can take the cursor to that location (using the arrow keys) and perform the
required operation. 
4.In addition, the user should is able to save and load the data in a text file using S and L respectively. The
program will automatically save the data in file save.txt, and load the data from the same file.
5.Internally, the notepad is composed of two-dimensional doubly linked list. Its implementation is just like
a doubly linked list with an additional property that it can grow in two dimensions. 
6.Since text can be written on multi lines, each row of the 2D-linkedlist represents one line. Each line is terminated when a
newline is inserted in the ADT. Each node contains four links which it uses to connect to node before,
after, below and above it. In addition each node can store a character.
