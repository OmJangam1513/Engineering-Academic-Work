def solve_n_queen(n):
    
    board = [-1]*n

    solution = []

    cols = set()
    post_diag = set()
    neg_diag = set()

    def backtracking(row):
        
        if row == n:
            solution.append(list(board))

        for col in range(n):
            
            if col in cols or row + col in post_diag or row - col  in neg_diag:
                continue
            
            board[row] = col
            cols.add(col)
            post_diag.add(row+col)
            neg_diag.add(row-col)

            backtracking(row+1)

            cols.remove(col)
            post_diag.remove(row+col)
            neg_diag.remove(row-col)

    backtracking(0)

    return solution

def print_solution(solution):

    for sol in solution:
        for row in sol:
            line =[]
            for i in range(n):
                if row == i:
                    line.append('Q')
                else:
                    line.append('.')
            print(" ".join(line))
        
        print("=================================")


n = 4

solution = solve_n_queen(n)

print_solution(solution)