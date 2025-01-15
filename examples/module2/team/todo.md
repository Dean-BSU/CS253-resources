# Problem Description

Output each floating-point value with two digits after the decimal point, which can be achieved as follows:<br />`printf("%0.2lf", yourValue);`

<br />
1. Prompt the user to enter five numbers, being five people's heights. Store the numbers in an array of doubles. Output the array's numbers on one line, each number followed by one space.
<br /><br />

## Expected Program Output (with sample user input)
```
Enter height 1:
56.0
Enter height 2:
60.0
Enter height 3:
58.0
Enter height 4:
59.0
Enter height 5:
57.0
You entered: 56.00 60.00 58.00 59.00 57.00 

```
<br /> 
2. Also output the total height, by summing the array's elements. 

<br /> 
3.  Also output the average of the array's elements.  

<br /> 
4.  Also output the max array element.  
<br /><br />

## Expected Program Output (with sample user input)
```
Enter height 1:
56.0
Enter height 2:
60.0
Enter height 3:
58.0
Enter height 4:
59.0
Enter height 5:
57.0
You entered: 56.00 60.00 58.00 59.00 57.00 

Total height: 290.00
Average height: 58.00
Max height: 60.00

```

Output each floating-point value with two digits after the decimal point, which can be achieved as follows:<br />`printf("%0.2lf", yourValue);`


# Error Handling
The following describes the expected behavior in the event of unexpected user input
- If the user inputs a non-numerical height value, simply prompt for the height value again.
- Something to think about... Does it make sense to allow the user to enter negative values for height in this situation? 
