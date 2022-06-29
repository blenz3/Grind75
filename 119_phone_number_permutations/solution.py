class Solution(object):
    
    MAPPED_CHARACTERS = {
        '1' : '',
        '2' : 'abc',
        '3' : 'def',
        '4' : 'ghi',
        '5' : 'jkl', 
        '6' : 'mno',
        '7' : 'pqrs',
        '8' : 'tuv',
        '9' : 'wxyz'
    }
    
    # Strategy
    #   - For each character mapped to a digit create a substring for each
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        return self._permute(digits, '', []) if digits else []
        
        
    def _permute(self, digits, path, combinations):
        if not digits:
            return combinations + [path]
        
        for mapped_character in Solution.MAPPED_CHARACTERS.get(digits[0], []):
            combinations = self._permute(digits[1:], path + mapped_character, combinations)
            
        return combinations
