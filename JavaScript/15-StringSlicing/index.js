// string slicing: creating a substring from a portion of another string without altering the original string

const fullName = 'Bro Code';

let firstName = fullName.slice(0,3); // the start index is inclusive & end index is exclusive 
console.log(firstName);

let lastName = fullName.slice(4); //slice(,3) doesn't work
console.log(lastName);

let firstChar = fullName.slice(0,1); // B
console.log(firstChar);

let lastChar = fullName.slice(-3); //ode
console.log(lastChar);

// ------------------------------------------------------

firstName = fullName.slice(0,fullName.indexOf(' '));
lastName = fullName.slice(fullName.indexOf(' ')+1);
console.log(`${firstName} ${lastName}`);

// ------------------------------------------------------