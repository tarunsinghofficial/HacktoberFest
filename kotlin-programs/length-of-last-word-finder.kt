fun main(args: Array<String>) {
    print(lengthOfLastWord("Hello World"))
}
fun lengthOfLastWord(s: String): Int {
    var s_arr = s.split(" ")
    var result = 0;
    for (i in (0..s_arr.lastIndex).reversed())
        if (s_arr[i].isNotEmpty()) {
            result = s_arr[i].length
            break
        }
    return result
}