let userName = 'Bro Code';

console.log(userName.charAt(0)); // returns the character at the given index

console.log(userName.indexOf('o')); // returns the index of first occurance  
console.log(userName.lastIndexOf('o')); // returns the index of last occurance

console.log(userName.length); // 8

let userName1 = '  Coop  '
// trims spaces at the beginning or end
console.log(userName1.trim()); // Coop

console.log(userName.toLowerCase()); // bro code
console.log(userName.toUpperCase()); // BRO CODE

console.log(userName.repeat(3)); // Bro CodeBro CodeBro Code

console.log(userName.startsWith('b')); // false
console.log(userName.endsWith('e')); //true

console.log(userName.includes('d')); // true

let phoneNumber1 = '123-456-789';
phoneNumber = phoneNumber1.replaceAll('-','');
console.log(phoneNumber); // 123456789
let phoneNumber2 = '123-456-789'; 
phoneNumber2 = phoneNumber2.padStart(15, '0'); // first arguement is the length that we need and 2nd arguement fills it with the value specified
console.log(phoneNumber2); //0000123-456-789

