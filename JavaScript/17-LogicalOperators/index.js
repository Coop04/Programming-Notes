// Logical operators: used to combine or manipulate values (true or false)
// and: &&
// or: ||
// not: !

const temp = 20;

if(temp > 0 && temp <= 30) {
    console.log('The weather is good');
}
else {
    console.log('The weather is bad');
}

// --------------------------------------

const isSunny = true;
if(!isSunny) {
    console.log('It is sunny');
}
else {
    console.log('It is cloudy');
}