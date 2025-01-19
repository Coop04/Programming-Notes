// Method CHaining: Calling one method after another in one continuous line of code

// No method chaining
const noChain = [3, 1, 4, 1, 5, 9];
const sorted = noChain.sort();
const reversed = sorted.reverse();
console.log(reversed);
// with method chaining
const withChain = [3, 1, 4, 1, 5, 9].sort().reverse();
console.log(withChain);