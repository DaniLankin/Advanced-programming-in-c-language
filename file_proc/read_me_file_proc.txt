Write a function that receives a ID of the customer, 
the amount of his new purchase, and a string containing the name of the file.
The function must update information for the customer in the file by adding the 
amount of the new purchase to the total amount of the customer's purchases.

For example, for the file with the following content:
 
06842151 Moshe 71.25
330578795 Benjamin 1755.65
 20051546 Dina 560.10

and No. i.d. "330578795" and the amount of the new purchase equal to 200.1 The updated content of the file after calling the function will be:

06842151 Moshe 71.25
330578795 Benjamin 1955.75
20051546 Dina 560.10

The function will return true if the operation was performed successfully. 
The function will return false if the customer ID number is not in the file or if the file is not opened.
1. Write a program that creates the text file and runs the function from section 1.

2. Write a function as in section 1 with a binary file instead of a text file.