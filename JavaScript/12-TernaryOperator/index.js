// ternary operator: a shortcut to if{} and else{} statements helps to assign a variable based on a condetion 
// condetion ? codeIfTrue : codeIfFalse;

let age = 21;
let message1 = age >= 18 ? `You are an adult` : `You are a minor`
console.log(message1);

// ----------------------------------------------------------------

let isStudent = true;
let message2 = isStudent ? 'You are a student' : 'You are not a student';
console.log(message2);

// -----------------------------------------------------------------

let purchaseAmount = 1000;
let discount = purchaseAmount >=100 ? 10 : 0;
console.log(`Your total is $${purchaseAmount-(purchaseAmount*(discount/100))}`);