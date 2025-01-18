// variable = A container that stores a value.
//            Behaves as if it were the value it contains.

// 1. declaration   let x;
// 2. assignment    x=100;

let x;
x = 100;

console.log(x);

let y = 432; // or we can do both declaration and assignment in the same line
console.log(y);

// number
let age = 25;
let price = 10.99;
let gpa = 2.1;

console.log(age);
console.log(price);
console.log(gpa);

console.log(`You are ${age} years old`); // if we use "" or '' instead of `` we cant use ${}
console.log(`THe price is: $${price} cents`);
console.log(`Your gpa is: ${gpa}`);

console.log(typeof age); // to display datatype
console.log(typeof price); // number

// string
let firstName = "Bro"; // can use either "" or ''
let favourateFood = 'pizza'
let email = 'aswanthsatheesh432@gmail.com'

console.log(typeof firstName)
console.log(firstName);
console.log(`Your name is ${firstName}`); 
console.log(`You like ${favourateFood}`);
console.log(`Your email is ${email}`);

// booleans (true/false)
let online = true;
let forsale = false;

console.log(typeof online);
console.log(`Bro is online: ${online}`);
console.log(`Is this car for sale: ${forsale}`)

// --------------------------------------------------------------

// to show in the web page 
let fullName = "Bro Code"; //string
let age1 = 25;             //number
let isStudent = true;      //boolean

document.getElementById('p1').textContent=`Your name is ${fullName}`;
document.getElementById('p2').textContent=`You are ${age} years old`;
document.getElementById('p3').textContent=`Enrolled: ${isStudent}`;