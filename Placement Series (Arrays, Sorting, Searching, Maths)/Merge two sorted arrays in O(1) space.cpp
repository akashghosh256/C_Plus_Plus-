Merge two sorted arrays in O(1) space

First, we have to traverse array1 and then compare it with the first element of array2. 
If it is less than array1 then we swap both.
 
After swapping we are going to sort the array2 again so that the smallest element of the array2 
comes at the first position and we can again swap with the array1
To sort the array2 we will store the first element of array2 in a variable and left shift all the elements and store
the first element in array2 in the last.


import java.io.*;

class gfg {

	public static void mergeArray(int[] arr1, int[] arr2)
	{

		// length of first arr1
		int n = arr1.length;

		// length of second arr2
		int m = arr2.length;

		// Now traverse the array1 and if
		// arr2 first element
		// is less than arr1 then swap
		for (int i = 0; i < n; i++) {

			if (arr1[i] > arr2[0]) {

				// swap
				int temp = arr1[i];
				arr1[i] = arr2[0];
				arr2[0] = temp;

				// after swapping we have to sort the array2
				// again so that it can be again swap with
				// arr1

				// we will store the firstElement of array2
				// and left shift all the element and store
				// the firstElement in arr2[k-1]

				int firstElement = arr2[0];

				int k;
				for (k = 1;
					k < m && arr2[k] < firstElement;
					k++)
				{
					arr2[k - 1] = arr2[k];
				}
				arr2[k - 1] = firstElement;
				System.out.println("\nAfter Sorting arr2[] .....");
				for(int j: arr2){
 				System.out.print(j + ", ");}


			}
		}
		System.out.println(" \nArrays are :.............");
		// read the arr1
		for (int i : arr1) {
			System.out.print(i + " ");
		}

		System.out.println();

		// read the arr2
		for (int i : arr2) {
			System.out.print(i + " ");
		}
	}

	// Driver Code
	public static void main(String[] args)
	{
		 int[] arr1 = { 1, 3, 5, 7 };
 
        int[] arr2 = { 0, 2, 6, 8, 9 };
		mergeArray(arr1, arr2);
	}
}


GAO METHOD-----------------------------------------------------------------

// Java program for Merging two sorted arrays
// with O(1) extra space

public class GFG {

	// Function to find next gap.
	private static int nextGap(int gap)
	{
		if (gap <= 1)
			return 0;
		return (gap / 2) + (gap % 2);
	}

	private static void merge(int[] arr1,
							int[] arr2, int n,
							int m)
	{
		int i, j, gap = n + m;
		for (gap = nextGap(gap); gap > 0;
			gap = nextGap(gap))
		{
			// comparing elements in the first
			// array.
			for (i = 0; i + gap < n; i++)
				if (arr1[i] > arr1[i + gap])
				{
					int temp = arr1[i];
					arr1[i] = arr1[i + gap];
					arr1[i + gap] = temp;
				}

			// comparing elements in both arrays.
			for (j = gap > n ? gap - n : 0;
				i < n && j < m;
				i++, j++)
				if (arr1[i] > arr2[j])
				{
					int temp = arr1[i];
					arr1[i] = arr2[j];
					arr2[j] = temp;
				}

			if (j < m)
			{System.out.println("ENTERING if (j < m) when gap = " +gap );  //GAP =1
				// comparing elements in the
				// second array.
				for (j = 0; j + gap < m; j++)
					if (arr2[j] > arr2[j + gap])
					{
						int temp = arr2[j];
						arr2[j] = arr2[j + gap];
						arr2[j + gap] = temp;
					}
			}
		}
	}

	// Driver Code
	public static void main(String[] args)
	{
		int[] a1 = { 10, 27, 38, 43, 82 };
		int[] a2 = { 3, 9 };

		// Function Call
		merge(a1, a2, a1.length, a2.length);

		System.out.print("First Array: ");
		for (int i = 0; i < a1.length; i++) {
			System.out.print(a1[i] + " ");
		}

		System.out.println();

		System.out.print("Second Array: ");
		for (int i = 0; i < a2.length; i++) {
			System.out.print(a2[i] + " ");
		}
	}
}

// This code is contributed by Vinisha Shah


