class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
	    # reorder chars by their count
        (fst, x), (snd, y), (thd, z) = sorted([(a, 'a'), (b, 'b'), (c, 'c')], reverse=True)
		# divide the char with the max count into 2-char groups
        groups = [x + x] * (fst // 2)
		# if there's one more char left
        if fst % 2 == 1:
            groups.append(x)
        num_groups = len(groups)
		# start appending separators from the first group
        group_idx = 0
        for count, char in [(snd, y), (thd, z)]:
            for _ in range(count):
			    # append one char a time, and go back to the first group if necessary 
                groups[group_idx % num_groups] += char
                group_idx += 1
		# concatenate valid groups all together
        return ''.join(groups[:min(num_groups, group_idx + 1)])