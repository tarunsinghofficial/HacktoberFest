# sudoku

![sudokuNEW](https://user-images.githubusercontent.com/68727041/164480337-b834fdb6-9e45-4368-adfc-0f9fcb68fd83.png)

### Purpose
- A JAVA GUI Desktop application to solve sudoku puzzles using optimized breadth first search.<br>
- Can solve puzzles with >=23 tiles filled.<br>
- Algorithm fails below 23 filled tiles, as possibilities increase exponentially during calculations which causes extrememly high computational times.<br/>

**Let's talk about the way a brute force algorithm would solve a sudoku puzzle.**

<br>

### Implementation

Brute Force Algorithm for Solving a Sudoku puzzle:
<br>
For those readers unfamiliar with the working principle of a sudoku puzzle, here's a well-paced explanation of the Board:
<br>
A Sudoku Board consists of a 9*9 grid, divided into 3*3 regions or blocks.
<br>
The objective is to fill the 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that make 
up the grid contain all of the digits from 1 to 9. The puzzle provides a partially completed grid, which for most puzzles has a single solution.
<br>
Understanding the problem:
<br><br>
Now the question is: How would a computer solve this puzzle? Considering  programmers who solve sudoku puzzles regularly themselves, they would probably add in extra functions and subprocesses which streamline which numbers are chosen to fill in a particular grid box, but what if you know absolutely nothing about solving a sudoku puzzle, what if you've never solved a puzzle in your whole life? You're simply given the rules for filling a number into a particular grid box, How would the computer decide which number is correct?<br>

The answer to this is-perhaps using a brute force algorithm, try every possible combination of number substitution in the board? Then, using a checking algorithm, check which of the combinations follow the rules of the puzzle, select that puzzle, and return it.<br>

While this approach is a mathematical possibility, it is not a viable solution. The number of boards that would be presented as possible solutions will almost definitely exceed the memory delegated to your solver program. Another approach would be to combine the code which creates the solution for the board and the one which checks the substitutions(of numbers into empty cells) performed. This would be perfect, except for the fact that the initial phase of solving a sudoku puzzle renders multiple possible solutions for a single grid box, but given the existence of only a single final solution, the other substitutions are almost definitely wrong and will lead to problems while solving the puzzle later on:<br>

Consider an unsolved board, the first subregion's first row could be filled as follows: 9,5,7.<br>

But looking at the unsolved puzzle, the solutions at first glance do not seem binary.<br>

In place of 9, I might have decided to substitute 5, this would not seem to be wrong initially as there are still grid boxes left to fill, however, you will hit a point in the grid wherein there are no other solutions possible, because of a seemingly correct number substitution earlier in the game. Some readers may offer that the program can backtrack from the last incorrect substitution and continue solving the puzzle with other solutions.

This would be a viable solution- Provided you knew which grid box you filled incorrectly.

This leaves us at a deadlock- Our program knows the rules to fill in a particular grid box but doesn't know which substitution of the available ones is correct, The problem is further compounded when each grid box has multiple solutions, of which only one is correct, leading to a branching sort of solutions' tree.

The Solution:

A simple solution is available for our program- <br>

Solve the board linearly, grid boxes in region/block 1 will be solved first then 2, up to 9, in order.<br>

Create an array of boards, where you store boards that are possible solutions and maintain a loop that parses each board while solving it, cell by cell.<br>

Keep in mind that the original board will be parsed first, up to a point where there are multiple possible substitutions for one grid box, at which point, one board will be created for each substitution and filled with the substitution, after which the parent board gets deleted and the loop starts parsing the children board from the cell where the parser left off in the parent board. The process is repeated till a solution is obtained.<br>

1)ENSURE that the code which substitutes numbers into blank grid boxes chooses numbers from an array that contains solutions that are NOT already present in the region, specific row, or specific column.<br>

2)There might be multiple solutions for a particular grid box. When this happens, CLONE the board, i.e duplicate the configuration of the board and pass each substitution into an alternate version of the original parent board. Now remove the parent board from the array, add the children boards.<br>

Meaning, suppose the particular grid box we are solving has possible solutions 1, 3, and 5 create a COPY of the original board and fill one with 3 at the required grid box, one with 1, and one with 5 at the required cell.<br>

Add these three to the array containing possible solution boards and remove the parent board.
<br>
3)Continue solving each copy of the board, creating children every time the parent board has more than one possible substitution at the grid box you are solving, and then remove the parent board.
<br>
4)Boards at which you have made an incorrect substitution will stop providing children at a specific grid box, these boards will be automatically deleted while parsing the array of possible solution boards.
<br>
5) Once the final grid box/ cell is solved, there will usually be only one child board left.
Provide the user with this board.
<br>
Explore the Sudoku folder to read the source code and download the Sudoku zip file to use the application.<br>
The application GUI is built with AWT/SWING.

