class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        result = []
        
        # Generate all possible sequential numbers
        for start in range(1, 10):          # starting digit 1-9
            num = start
            for next_digit in range(start + 1, 10):
                num = num * 10 + next_digit
                if num > high:
                    break
                if num >= low:
                    result.append(num)
        
        result.sort()   # though they are almost sorted already
        return result