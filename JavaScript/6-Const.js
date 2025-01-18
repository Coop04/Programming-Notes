//  const: a variable that can't be changed (constant)

const PI = 3.14159; // it is good practice to make all the letters in const to uppercase id datatype is premitive (Number or Boolean) and not done for Strings
let radius;
let circumfrence;

// PI = 55.43; // trying to overwrite the value of constant causes error

radius = window.prompt('Enter the radius of a circle');
radius = Number(radius);
circumfrence = 2 * PI * radius;
console.log(circumfrence);
// document.getElementById('myP').textContent=`Circumfrence = ${circumfrence}`;

// ------------------------------------------------------------------------------

// rewriting the program with html box input (professional method)
let radius1;
let circumfrence1;
document.getElementById('myButton').onclick = function(){
    radius1 = Number(document.getElementById('myInput').value);
    circumfrence1 = 2 * PI * radius1
    document.getElementById('myPexp6').textContent = `Circumference of the circle: ${circumfrence1} cm`;
}