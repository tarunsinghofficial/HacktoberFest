<script>
	
// Java Script program to search an element in row-wise
// and column-wise sorted matrix

function search(mat,n,x) {
	if (n == 0)
		return -1;

	// traverse through the matrix
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < n; j++)
			// if the element is found
			if (mat[i][j] == x) {
				document.write("Element found at ("
						+ i + ", " + j
						+ ")<br>");
			return 1;
		}
	}

	document.write(" Element not found");
	return 0;
}

	let mat = [[ 10, 20, 30, 40 ],
				[15, 25, 35, 45] ,
				[ 27, 29, 37, 48 ],
				[ 32, 33, 39, 50 ]];

	search(mat, 4, 29);

//contributed by 171fa07058
</script>
