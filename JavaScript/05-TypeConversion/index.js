// type conversion: change the datatype of value to another
//                  (string, number, boolean)

let age = window.prompt('How old are you?'); // input is read as string
age = Number(age);
age +=1;
console.log(age, typeof(age));

// -----------------------------------------------------

let x = 'pizza';
let y = 'pizza';
let z = 'pizza';
let p = '';
let q = '';
let r; // declared but unassigned variable

x = Number(x); 
y = String(y); 
z = Boolean(z); // typecasting to boolean helps to understand if something is typed in or is it empty
p = Number(p); 
q = Boolean(q);
r1 = Number(r);
r2 = String(r);
r3 = Boolean(r);


console.log(x, typeof(x)); // Nan 'number'
console.log(y, typeof(y)); // pizza 'string'
console.log(z, typeof(z)); // true 'boolean'
console.log(p, typeof(p)); // 0 'number'
console.log(q, typeof(q)); // false 'boolean'
console.log(r1, typeof(r1)); // NaN 'number'
console.log(r2, typeof(r2)); // undefined string
console.log(r3, typeof(r3)); // false 'boolean'

// ------------------------------------------------