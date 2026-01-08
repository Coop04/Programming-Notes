# ===================== BITWISE SHIFT (<<, >>) QUICK NOTES =====================
# Bitwise shift operators move bits LEFT or RIGHT in the binary representation
# of integers.
#
# Operators:
#   <<   Left Shift
#   >>   Right Shift
#
# These are BITWISE operators (operate on bits, not values).
#
# ============================================================================
# LEFT SHIFT (<<)
#
# Rule:
#   Shift bits LEFT by n positions
#   Fill RIGHT side with 0s
#
# Effect (for positive numbers):
#   a << n  ==  a * (2^n)
#
# Example:
#   5 = 00000101
#   5 << 1 → 00001010 = 10
#   5 << 2 → 00010100 = 20
#
# Properties:
#   a << 0 = a
#   a << 1 = a * 2
#   a << n = a * (2^n)
#
# ============================================================================
# RIGHT SHIFT (>>)
#
# Rule:
#   Shift bits RIGHT by n positions
#
# Filling:
#   Positive numbers → 0
#   Negative numbers → 1 (sign bit preserved)
#
# Effect (for positive numbers):
#   a >> n  ==  a // (2^n)
#
# Example:
#   10 = 00001010
#   10 >> 1 → 00000101 = 5
#   20 >> 2 → 00000101 = 5
#
# Properties:
#   a >> 0 = a
#   a >> 1 = a // 2
#   a >> n = a // (2^n)
#
# ============================================================================
# NEGATIVE NUMBERS (IMPORTANT)
#
# Python uses ARITHMETIC RIGHT SHIFT
# → sign bit is preserved
#
# Example:
#   -8 >> 1 = -4
#
# Python DOES NOT support logical right shift (>>>)
#
# ============================================================================
# COMMON MISTAKES
#
# ❌ Thinking shifts work like string shifts
# ❌ Ignoring sign-bit behavior
# ❌ Replacing * or // blindly without understanding
#
# ============================================================================
# WHY SHIFTS ARE USED
#
# - Fast power-of-two operations
# - Bit masks & flags
# - Encoding / compression
# - Low-level systems programming
# - Competitive programming
#
# ============================================================================
# MOST COMMON INTERVIEW QUESTIONS (THEORY)
#
# Q1: Difference between << and >>?
#     << shifts left (multiply by 2^n)
#     >> shifts right (divide by 2^n)
#
# Q2: What is 3 << 2?
#     3 = 11 → 1100 = 12
#
# Q3: What is 16 >> 3?
#     16 / 8 = 2
#
# Q4: What happens when shifting negative numbers?
#     Sign bit is preserved in Python.
#
# Q5: Does Python have unsigned right shift?
#     ❌ No
#
# ============================================================================
# MOST COMMON PROGRAMMING QUESTIONS (VERY IMPORTANT)
#
# ---------------------------------------------------------------------------
# Q1: Multiply a number by 2^n without using *
#
# Example:
#   multiply(5, 3) → 40
#
# Solution:
#   result = 5 << 3
#
# ---------------------------------------------------------------------------
# Q2: Divide a number by 2^n without using /
#
# Example:
#   divide(32, 2) → 8
#
# Solution:
#   result = 32 >> 2
#
# ---------------------------------------------------------------------------
# Q3: Check if a number is even or odd using bitwise operators
#
# Logic:
#   LSB (rightmost bit) determines parity
#
# Code:
#   if n & 1 == 0:
#       even
#   else:
#       odd
#
# ---------------------------------------------------------------------------
# Q4: Check if a number is a power of 2
#
# Logic:
#   Power of 2 → only ONE bit set
#
# Code:
#   n > 0 and (n & (n - 1)) == 0
#
# Examples:
#   8  → True
#   10 → False
#
# ---------------------------------------------------------------------------
# Q5: Find 2^n using bitwise operators
#
# Logic:
#   1 shifted left by n
#
# Code:
#   1 << n
#
# Example:
#   1 << 5 = 32
#
# ---------------------------------------------------------------------------
# Q6: Swap two numbers without a temporary variable (XOR + shift topic)
#
# Code:
#   a = a ^ b
#   b = a ^ b
#   a = a ^ b
#
# ---------------------------------------------------------------------------
# Q7: Set the nth bit of a number
#
# Logic:
#   Use left shift as a mask
#
# Code:
#   n | (1 << k)
#
# ---------------------------------------------------------------------------
# Q8: Clear the nth bit of a number
#
# Code:
#   n & ~(1 << k)
#
# ---------------------------------------------------------------------------
# Q9: Toggle the nth bit of a number
#
# Code:
#   n ^ (1 << k)
#
# ---------------------------------------------------------------------------
# Q10: Count number of set bits (intro-level version)
#
# Logic:
#   Repeated right shifts
#
# Code:
#   count = 0
#   while n > 0:
#       count += n & 1
#       n >>= 1
#
# ============================================================================
# ONE-LINE INTERVIEW SUMMARY
#
# Bitwise shift operators move bits left or right.
# Left shift multiplies by powers of two,
# right shift divides by powers of two (for positives),
# and shifts are heavily used in bit manipulation problems.
# ============================================================================
