def yahtzee_upper(dicerolls):
    return max(i * dicerolls.count(i) for i in range(1, 7))

print(yahtzee_upper([2, 3, 5, 5, 6])) # => 10
print(yahtzee_upper([1, 1, 1, 1, 3])) # => 4
print(yahtzee_upper([1, 1, 1, 3, 3])) # => 6
print(yahtzee_upper([1, 2, 3, 4, 5])) # => 5
print(yahtzee_upper([6, 6, 6, 6, 6])) # => 30