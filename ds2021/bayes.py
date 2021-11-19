# Calculate the probability of A with cond B == P(A|B)
# P(A|B) = P(B|A) * P(A) / P(B)

P_A = 1        # P(A)
P_B = 1        # P(B)
P_BA = 1       # P(B|A)

# P(A) or P(B) needed to be calculated with total probability
# P(A) = sum(P(A)|Bi) * P(Bi) with i = range(1,n+1)
# e.g. P(A) = P(A|B1)*P(B1) + P(A|B2)*P(B2) + P(A|B3)*P(B3)
# B1 -> Bn are outcomes of B

# e.g. in case of B has 2 outcomes:
# P_A = P_AB * P_B + (1-P_AnotB) * P(notB)


# P(A∩B∩C | D) = P(A|D) * P(B|D) * P(C|D)