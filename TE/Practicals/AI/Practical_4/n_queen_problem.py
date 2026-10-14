def solve_n_queens(n):
    board = [-1] * n
    solutions = []

    cols = set()
    pos_diag = set()  
    neg_diag = set()  

    def backtrack(row):
        if row == n:
            solutions.append(list(board))
            return

        for col in range(n):
            if col in cols or (row + col) in pos_diag or (row - col) in neg_diag:
                continue

            board[row] = col
            cols.add(col)
            pos_diag.add(row + col)
            neg_diag.add(row - col)

            backtrack(row + 1)

            cols.remove(col)
            pos_diag.remove(row + col)
            neg_diag.remove(row - col)

    backtrack(0)
    return solutions

def print_solutions(solutions, n):
    for sol in solutions:
        for row in sol:
            line = []
            for i in range(n):
                if i == row:
                    line.append("Q")
                else:
                    line.append(".")
            print(" ".join(line))
        
        print("\n" + "-"* (2*n-1) + "\n")

n = 4

found_solutions = solve_n_queens(n)

print(f"Found {len(found_solutions)} solutions for {n}-Queens:\n")

print_solutions(found_solutions, n)