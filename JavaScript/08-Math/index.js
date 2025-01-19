// Math: built-in object that provides a collection of properties and methods

Math.PI

console.log(Math.PI);
console.log(Math.E);

let x = 3.12;
let y = 2;
let z;

z = Math.round(x);
z = Math.floor(y);
z = Math.ceil(x);
z = Math.trunc(x);
z = Math.pow(x,y);
z = Math.sqrt(81);
z = Math.log(10);

// trigonometry
z = Math.sin(45);
z = Math.cos(45);
z = Math.tan(45);

z = Math.abs(-31);
z = Math.sign(-31); // 1
z = Math.sign(21); // -1

let max = Math.max(x,y,z);
console.log(max);
let min = Math.min(x,y,z);
console.log(min);

console.log(z);
 