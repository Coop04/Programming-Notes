// Switch: can be efficient replacement to many else if statements

let day = 3;

switch(day) {
    case 1:
        console.log('Monday');
        break;
    case 2:
        console.log('Tuesday');
        break;
    case 3:
        console.log('Wednesday');
        break;
    case 4:
        console.log('Thursday');
        break;
    case 5:
        console.log('Friday');
        break;
    case 6:
        console.log('Saturday');
        break;
    case 7:
        console.log('sunday');
        break;
    default:
        console.log('Error');
}

// -------------------------------------------

let testScore = 32;
let letterGrade;

switch (true) {
    case (testScore >= 90):
        letterGrade = 'A';
        break;
    case (testScore >= 80):
        letterGrade = 'B';
        break;
    case (testScore >= 70):
        letterGrade = 'C';
        break;
    case (testScore >= 60):
        letterGrade = 'D';
        break;
    default:
        letterGrade = 'F';
}

console.log(`The letter grade is ${letterGrade}`);