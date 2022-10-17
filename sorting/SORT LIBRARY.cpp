
Asccending Order------------------------------------------------------------------
Arrays.sort(intervals, (a, b) -> a[0] - b[0]);   
OR Arrays.sort(intervals, (a, b) -> a - b);       int[][] intervals = {{1,3},{8,10},{15,18},{2,6}}; for 2D Arrays
Arrays.sort(intervals, (a, b) -> b[0] - a[0]);  // descending order 

When you sort an array with .sort(), it assumes that you are sorting strings. 
When sorting numbers, the default behavior will not sort them properly.

The function that you pass tells how to sort the elements. 
It takes two parameters (a and b) that represent any two elements from the array. 
How the elements will be sorted depends on the function’s return value:

if it returns a negative value, the value in a will be ordered before b.
if it returns 0, the ordering of a and b won’t change.
if it returns a positive value, the value in b will be ordered before a.
When you pass the function (a, b) => a - b, you’re telling the .sort() function to sort 
the numbers in ascending order.


FOR 1D ARRAY

Arrays.sort(array);                    Integer[] array = { 99, 12, -8, 12, 34, 110, 0, 121, 66, -110 };
Arrays.sort(array, Collections.reverseOrder()); // descending order    


















