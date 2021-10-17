fun main() {
  val value = 5
  val result = factorial(value)

  println("Factorial of $value = $result")  
}

fun factorial(value: Int): Long {
  var result: Long = 1
  for (i in 1..value) {
    // result = result * 1
    result *= i.toLong()
  }
  return result
}