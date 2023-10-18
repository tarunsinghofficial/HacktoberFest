# Open a file in read mode
file_path = "sample.txt"
try:
    with open(file_path, "r") as file:
        # Read the contents of the file
        file_contents = file.read()
        print("File Contents:")
        print(file_contents)
except FileNotFoundError:
    print(f"File '{file_path}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")
