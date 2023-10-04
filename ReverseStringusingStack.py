def reverse_string_using_stack(string):
  """Reverses the order of characters in a string using a stack.

  Args:
    string: The string to reverse.

  Returns:
    The reversed string.
  """

  # Create a stack to store the characters of the string.
  stack = []

  # Push each character of the string onto the stack.
  for character in string:
    stack.append(character)

  # Pop each character from the stack and append it to the reversed string.
  reversed_string = ""
  while stack:
    reversed_string += stack.pop()

  # Return the reversed string.
  return reversed_string

#main
print("Reverse String Using Stack")
str=input()
reverseStr=reverse_string_using_stack(str)
print(reverseStr)