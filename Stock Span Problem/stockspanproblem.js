<script>
// javascript linear time solution for stock span problem

	// A stack based efficient method to calculate
	// stock span values
	function calculateSpan(price , n , S)
	{
	
		// Create a stack and push index of first element
		// to it
		var st = [];
		st.push(0);

		// Span value of first element is always 1
		S[0] = 1;

		// Calculate span values for rest of the elements
		for (var i = 1; i < n; i++) {

			// Pop elements from stack while stack is not
			// empty and top of stack is smaller than
			// price[i]
			while (st.length!==0 && price[st[st.length - 1]] <= price[i])
				st.pop();

			// If stack becomes empty, then price[i] is
			// greater than all elements on left of it, i.e.,
			// price[0], price[1], ..price[i-1]. Else price[i]
			// is greater than elements after top of stack
			S[i] = (st.length===0) ? (i + 1) : (i - st[st.length - 1]);

			// Push this element to stack
			st.push(i);
		}
	}

	// A utility function to print elements of array
	function printArray(arr) {
		document.write(arr);
	}

	// Driver method
	
		var price = [ 10, 4, 5, 90, 120, 80 ];
		var n = price.length;
		var S = Array(n).fill(0);

		// Fill the span values in array S
		calculateSpan(price, n, S);

		// print the calculated span values
		printArray(S);

// This code contributed by Rajput-Ji
</script>
