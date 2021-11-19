# class Solution:
#     def numMatchingSubseq(self, s: str, words: List[str]) -> int:
#       cnt = 0
#       for w in words:
#         last_index = s.find(w[0])
#         if len(w) == 1:
#           if last_index >= 0: cnt+=1
#         else:
#           for i in range(1, len(w)):
#             index = s[last_index:].find(w[i])
#             if index < 0: break
#             last_index = index
#           cnt+=1
#       return cnt

def numMatchingSubseq(s: str, words) -> int:
  cnt = 0
  flag = True
  for w in words:
    last_index = s.find(w[0])
    if len(w) == 1:
      if last_index >= 0: cnt+=1
    else:
      for i in range(1, len(w)):
        index = s[last_index+1:].find(w[i])
        if index < 0:
          flag = False
          break
        last_index = index
      if flag:cnt+=1
      flag = True
  return cnt

def numMatchingSubseq1(s: str, words) -> int:
  cnt = 0
  for w in words:
    i = 0
    j = 0
    while j < len(w) and i < len(s):
      if (w[j] == s[i]):
        j+=1
      i += 1
    if (j == len(w)):
      cnt += 1
  return cnt


print(numMatchingSubseq("rwpddkvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvjubjgloeofnpjqlkdsqvruvabjrikfwronbrdyyjnakstqjac",
["wpddkvbnn","lnagtva","kvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvju","rwpddkvbnnugln","gloeofnpjqlkdsqvruvabjrikfwronbrdyyj","vbgeinupkvgmgxeaaiuiyojmoqkahwvbpwugdainxciedbdkos","mspuhbykmmumtveoighlcgpcapzczomshiblnvhjzqjlfkpina","rgmliajkiknongrofpugfgajedxicdhxinzjakwnifvxwlokip","fhepktaipapyrbylskxddypwmuuxyoivcewzrdwwlrlhqwzikq","qatithxifaaiwyszlkgoljzkkweqkjjzvymedvclfxwcezqebx"]
))