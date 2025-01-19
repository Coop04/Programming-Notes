// arithmetic operators = operands (values, variables, etc.)
//                        operators (+ - * /)
//                        eg: 11 = x + 5;

let students = 30;
students = students + 1; //or students += 1; 
students = students - 1;
students = students * 2;
students = students / 3;
students = students ** 2; // exponent
let extaStudents = students % 3; // modulus

// augmented assignment operators
students += 1;
students -= 1;
students *= 2;
students /= 4;
students **= 4;
students %= 4;

// increment and decrement operator
students++;
students--;

console.log(students)
console.log(extaStudents)

// --------------------------------------------------

/* operator precedence
    1. parenthesis ()
    2. exponents
    3. multiplication & devision & modulo
    4. addition & subtraction
*/

let result = 1 + 2* 3 + 4 ** 2;

console.log(result);