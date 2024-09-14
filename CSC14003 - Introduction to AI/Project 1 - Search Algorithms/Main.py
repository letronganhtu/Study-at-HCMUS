from Animations import run
from student_functions import DFS, BFS, UCS, GBFS, Astar
import numpy as np
import sys

def readMatrix(input):
    with open(input,'rt') as f:
        l=0
        matrix=[]
        for line in f:
            matrix.append(line.split())
        l+=1
        
    matrix=np.array(matrix).astype(int)

    return matrix


if __name__ == '__main__':
    """
        Argument from command line: `python main.py <input_file_path> <algorithm> <time_delay>(optional)`
        search_algorithm must be one of ['bfs', 'dfs', 'ucs', 'greedy', 'astar']
    """
    if (len(sys.argv)<3) or (len(sys.argv)>5):
        raise Exception("Wrong input!!!")
    input = str(sys.argv[1])
    al = str(sys.argv[2])
    if (len(sys.argv)==4):
        time_delay = int(sys.argv[3])
    else: time_delay=500
    # run(input, al, time_delay)

    matrix = readMatrix(sys.argv[1])
    for start in range(209):
        for end in range(209):
            if start == end:
                continue
            visited, path = UCS(matrix, start, end)
            if path != [] and path != [start, end]:
                print(start, end, path)