package main.algorithms.searching

fun main(args: Array<String>) {
    val input = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()  // to read an array (from user input)
    val eleToSearch = readLine()!!.trim().toInt()   // to read the element to be searched (from user input)
    val pos = binarySearchIterative(input, eleToSearch)
    if(pos >= 0 ) {
        println(pos)    // to print position at last
    } else {
        println("Position not found")
    }
}

fun binarySearchIterative(input: IntArray, eleToSearch: Int) : Int{
    var low = 0
    var high = input.size-1
    var mid:Int
    while(low <= high) {
        mid = low + ((high - low) / 2)
        when {
            eleToSearch >input[mid]   -> low = mid+1    // element is greater than middle element of array, so it will be in right half of array
            eleToSearch == input[mid] -> return mid // found the element
            eleToSearch < input[mid]  -> high = mid-1   //element is less than middle element of array, so it will be in left half of the array.
        }
    }
    return -1
}
