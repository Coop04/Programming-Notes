let randomNum1 = Math.random(); // Generates a random number between 0 & 1 (0 inclusive & 1 exclusive)

let randomNum2 = Math.floor(Math.random()*6); // Generates a random number between 0 and 6 (6 exclusive) and by using floor the value is floored

let randomNum3 = Math.floor(Math.random()*6)+1; // between 1 & 6

let randomNum4 = Math.floor(Math.random()*100)+1; // between 1 & 100
// -----------------------------------------------------------
const min = 50;
const max = 100;
let randomNum = Math.floor(Math.random()*(max-min))+min; 
//Math.random() generates a value between 0 (inclusive) and 1 (exclusive).
// Multiplying this by max scales the number to [0, max).Adding min shifts the range to [min, max + min).
// This is incorrect because the maximum value becomes max + min, not max.
console.log(randomNum);