// function = A section of code. 
// Declare code once, use it whenever you want. 
// Call the function to execute the code.

function hbDay(username,age) { // parameters
    console.log('Happy birthday to you');
    console.log('Happy birthday to you');
    console.log(`Happy birthday dear ${username}`);
    console.log(`You are ${age} years old`);
}

hbDay('Cooper',22); // arguements

// ------------------------------------------------

// return keyword
function add(x, y) {
    // let result = x+y;
    // return result;
    return x+y; 
}
console.log(add(14,10));

function sub(x, y) {
    return x-y; 
}
function mul(x, y) {
    return x*y; 
}
function div(x, y) {
    return x/y; 
}

function isEven(number) {
    return number%2 === 0 ? true: false;
}
console.log(isEven(30));

function isValid(email) {
    return email.includes('@') ? true : false;
}
console.log(isValid('Cooper@gmail.com'));