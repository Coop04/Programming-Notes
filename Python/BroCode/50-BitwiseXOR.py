# ===================== XOR (^) QUICK NOTES =====================
# XOR is a bitwise logical operator, NOT arithmetic addition.
#
# Rule (bit by bit):
#   0 ^ 0 = 0   (same bits → 0)
#   0 ^ 1 = 1   (different bits → 1)
#   1 ^ 0 = 1
#   1 ^ 1 = 0
#
# Key idea:
#   XOR keeps differences and removes similarities.
#
# Important properties:
#   a ^ a = 0          # same values cancel out
#   a ^ 0 = a          # XOR with 0 changes nothing
#   a ^ b ^ b = a      # reversible (b cancels itself)
#
# Special example (very important):
#   a ^ b ^ a = b
#   Explanation:
#     a ^ a = 0        # same values cancel
#     0 ^ b = b        # remaining value survives
#
# Why XOR looks like addition sometimes:
#   XOR behaves like binary addition *without carry*
#   If no bit position has (1 + 1), then:
#       a ^ b == a + b
#
# Why XOR is NOT real addition:
#   Binary addition generates carry bits (1 + 1 = 10)
#   XOR ignores carry completely (1 ^ 1 = 0)
#
# Example:
#   3 = 011
#   5 = 101
#   3 ^ 5 = 110 (6)   # carry ignored
#   3 + 5 = 1000 (8) # carry included
#
# CPU insight:
#   Binary addition can be built using:
#       SUM   = a ^ b
#       CARRY = a & b
# ===============================================================

# Classic interview example (why XOR is loved)

# Find the number that appears once
arr = [2, 3, 5, 4, 5, 3, 4]

res = 0
for x in arr:
    res ^= x

print(res)  # 2

# ------------------------------------------

# Swapping two variables (without temp)
a = 5
b = 9

a ^= b  # a = a ^ b
b ^= a  # b = a ^ b ^ b  -> b cancels out
a ^= b  # a = a ^ b ^ a  -> a cancels out

# ------------------------------------------
# Toggle a specific bit (very common use)

# Toggle the 3rd bit (0-indexed from right)
num = 10        # 1010
mask = 1 << 2   # 0100

num ^= mask     # toggles the bit
print(num)      # 14 (1110)

# ------------------------------------------
# Simple encryption / masking using XOR

data = 123
key = 77

encrypted = data ^ key
decrypted = encrypted ^ key

print(encrypted)
print(decrypted)  # original data restored

# ------------------------------------------
# Find TWO numbers that appear once (others appear twice)

arr = [1, 2, 3, 2, 1, 4]

xor_all = 0
for x in arr:
    xor_all ^= x   # result = 3 ^ 4

# Get rightmost set bit
diff_bit = xor_all & -xor_all

num1 = 0
num2 = 0

for x in arr:
    if x & diff_bit:
        num1 ^= x
    else:
        num2 ^= x

print(num1, num2)  # 3 4 (order may vary)

# ------------------------------------------
# Difference check using XOR

a = 25
b = 30

if a ^ b != 0:
    print("Values are different")
else:
    print("Values are same")

# ------------------------------------------
# XOR used to remove duplicates when order doesn't matter

arr = [7, 3, 7, 4, 4]
res = 0

for x in arr:
    res ^= x

print(res)  # 3
