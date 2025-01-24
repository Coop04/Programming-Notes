//  Spread Operator: ... allows an iterable such as an array or string to be expanded into seperate elements (unpack the elements)

let numbers = [1,2,3,4,5];

// let maximum = Math.max(numbers); // returns NaN
let maximum = Math.max(...numbers); 
let minimum = Math.min(...numbers);

console.log(maximum, minimum);

// ---------------------------------------

let username = 'Bro Code';
let letters = [...username];
console.log(letters); //['B', 'r', 'o', ' ', 'C', 'o', 'd', 'e']

let name = [...username].join('-'); // inside join() give the symbol to seperate with, use '' for no sumbol
console.log(name);

// ----------------------------------------

let fruits = ['apple', 'mango', 'orange', 'pineapple'];
// we can create a shallow copy of this array using the spread operator
// shallow copy: it is a different data structure but contains identical values
let newFruits = [...fruits];

console.log(fruits);
console.log(newFruits); // exactly the same as fruits

let vegetables = ['carrots', 'celery', 'potatoes'];
let food = [...fruits, ...vegetables];
console.log(food);
// we can also append elements 
let food2 = [...fruits, ...vegetables, 'eggs','salad'];
console.log(food2);