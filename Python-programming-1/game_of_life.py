import time
import os

WIDTH, HEIGHT = 20, 10

def print_grid(grid):
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear terminal (Windows or Linux)
    for row in grid:
        for cell in row:
            print('◼' if cell else '◻', end=' ')
        print()
    print()

def count_live_neighbors(grid, x, y):
    neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    count = 0
    for dx, dy in neighbors:
        nx, ny = (x + dx) % WIDTH, (y + dy) % HEIGHT  # Wrap around edges
        if grid[ny][nx]:
            count += 1
    return count

def next_generation(grid):
    new_grid = [[False for _ in range(WIDTH)] for _ in range(HEIGHT)]
    for y in range(HEIGHT):
        for x in range(WIDTH):
            live_neighbors = count_live_neighbors(grid, x, y)
            if grid[y][x]:  # Cell is alive
                new_grid[y][x] = live_neighbors in [2, 3]  # Stay alive
            else:  # Cell is dead
                new_grid[y][x] = live_neighbors == 3  # Become alive if exactly 3 neighbors
    return new_grid

# Initialize the grid with a "glider" pattern
grid = [[False for _ in range(WIDTH)] for _ in range(HEIGHT)]
grid[1][2] = True
grid[2][3] = True
grid[3][1] = True
grid[3][2] = True
grid[3][3] = True

while True:
    print_grid(grid)
    grid = next_generation(grid)
    time.sleep(0.5)  # Pause for 500ms between generations
