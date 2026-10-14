import heapq

class PuzzelNode:

    def __init__(self, state, parent = None, move = "", depth = 0):
        self.state = state
        self.parent = parent
        self.move = move
        self.depth = depth
        self.zero_index = self.state.index(0)
        self.cost = self.depth + self.misplaced_tiles()

    def misplaced_tiles(self):

        goal_state = (1,2,3,4,5,6,7,8,0)

        count = 0 

        for i in range(9):

            if self.state[i] != 0 and self.state[i] != goal_state[i]:
                count +=1

        return count

    def get_neighbor(self):

        neighbors = []

        r, c = divmod(self.zero_index, 3)

        moves = {
            'UP': (r-1, c),
            'DOWN': (r+1 , c),
            'LEFT': (r, c-1),
            'RIGHT': (r, c+1)
        }

        for move_name, (nr,nc) in moves.items():

            if 0 <= nr < 3 and 0 <= nc < 3:
                new_zero_index = nr*3 + nc

                new_state = list(self.state)

                new_state[self.zero_index], new_state[new_zero_index] = new_state[new_zero_index], new_state[self.zero_index]

                neighbors.append(
                    PuzzelNode(tuple(new_state), self, move_name, self.depth+1)
                )

        return neighbors

    def __lt__(self, other):
        return self.cost < other.cost
        
def solve_8_puzzel(start_state):

    goal_state = (1,2,3,4,5,6,7,8,0)

    visited = set()

    start_node = PuzzelNode(tuple(start_state))
    visited.add(tuple(start_state))

    open_set = []

    heapq.heappush(open_set,start_node)

    while(open_set):

        current_node = heapq.heappop(open_set)

        if current_node.state == goal_state:
            return reconstruct_path(current_node)

        for neighbor in current_node.get_neighbor():

            if neighbor.state not in visited:
                visited.add(neighbor)
                heapq.heappush(open_set, neighbor)
        

def reconstruct_path(node):
    path = []

    while(node.parent):
        path.append((node.move, node.state))
        node = node.parent

    return path[::-1]



initial_board = [1,2,3,0,4,6,7,5,8]

solution = solve_8_puzzel(initial_board)

if(solution):

    print(f'Found Solution in {len(solution)}')

    for move, state in solution:
        
        print(f'Move: {move}')
        
        for i in range(0,9,3):
            print(state[i:i+3])
        print()


    