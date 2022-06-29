class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        subboxes = [set() for _ in range(9)]
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        
        for i in range(len(board)):
            for j in range(len(board[i])):
                value = board[i][j]
                if value == '.':
                    continue
                    
                is_valid = all([
                    self._checkValue(value, rows[i]),
                    self._checkValue(value, cols[j]),
                    self._checkValue(value, subboxes[self._getSubBox(i, j)])
                ])
                
                if not is_valid:
                    return False

                rows[i].add(value)
                cols[j].add(value)
                subboxes[self._getSubBox(i, j)].add(value)
                    
        return True

    def _checkValue(self, value, values):
        return value not in values

    def _getSubBox(self, row, col):
        return (3 * (row / 3)) + (col / 3)
        
        
