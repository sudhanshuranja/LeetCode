class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []
        
        # Get sorted unique values
        sorted_unique = sorted(set(arr))
        
        # Create rank map: value -> rank
        rank_map = {}
        for rank, val in enumerate(sorted_unique, 1):
            rank_map[val] = rank
        
        # Replace each element with its rank
        return [rank_map[val] for val in arr]