// rest operator: (...rest) allow a function work with a variable number of arguements by bundling them into an array

// spread: expands an array into seperate elements
// rest  : bundles seperate elements into an array

const food1 ='pizza';
const food2 ='burger';
const food3 ='hot dog';
const food4 ='sushi';

function openFridge(...foods) { // helps to add any no. of arguements
    console.log(foods); // ['pizza', 'burger', 'hot dog', 'sushi']
    console.log(...foods); // pizza burger hot dog sushi
}

openFridge(food1,food2,food3,food4); 
// ----------------------------------------

// combining seperate elements and bundling them to form an array
function getFood(...foods) {
    return foods;
}

const foods = getFood(food1,food2,food3,food4);

console.log(foods) // ['pizza', 'burger', 'hot dog', 'sushi']

// -----------------------------------------

function sum(...numbers) {
    let result = 0;
    for(let number of m=numbers) {
        result+=number;
    }
    return result;
}

const total = sum(1,4,6,9);
console.log(`Your total is ${total}`); // Your total is 20

// -----------------------------------------

function avg(...numbers) {
    let result = 0;
    for(let number of m=numbers) {
        result+=number;
    }
    return result/numbers.length;
}
const total1 = avg(1,4,6,9);
console.log(`Your average is ${total1}`); // Your average is 5

// -------------------------------------------

// Combining strings
function combineStrings(...strings) {
    return strings.join(' ')
}

const fullName = combineStrings('Mr.', 'Spongebob', 'Squarepants','III');
console.log(fullName); // Mr. Spongebob Squarepants III