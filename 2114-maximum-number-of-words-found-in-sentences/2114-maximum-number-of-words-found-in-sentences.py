class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        mx=-1
        for sentence in sentences:
            x = len(sentence.split())
            if(x>mx):
                mx=x
        return mx
        