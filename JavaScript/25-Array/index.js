// array :a variable like structure that can hold more than one value

let fruits = ['apple', 'orange', 'banana'];

fruits[0] = 'coconut';
fruits.push('kiwi'); // adds at the end
fruits.pop(); // remove from the end
fruits.unshift('mango'); // adds at the beginning
fruits.shift(); // removes from the beginning

console.log(fruits);
console.log(fruits[2]);

let numOfFruits = fruits.length;
let index = fruits.indexOf('banana'); // if the element is not in the list then returns -1

console.log(numOfFruits, index);

// ------------------------------------------

// to loop through the elements
for (let i=0; i<numOfFruits; i++) {
    console.log(fruits[i]);
}

// enhansed for loop
for (let fruit of fruits) {
    console.log(fruit);
}

// to sort an array
fruits.sort(); 
for (let fruit of fruits) {
    console.log(fruit);
}

// to sort in reverse
fruits.sort().reverse();
for (let fruit of fruits) {
    console.log(fruit);
}