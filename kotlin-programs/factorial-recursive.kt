fun main() {
  val value = 5
  val result = factorial(value)

  println("Factorial of $value = $result")  
}

fun factorial(value: Int): Long {
  if(value <= 1){
    return 1
  }

  return value * factorial(value - 1)
} 