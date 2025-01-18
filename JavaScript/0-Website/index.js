// If Statement

age = window.prompt('Enter your age:');

if(age >= 18){
    console.log(`You are old enough to enter this site!`)
}
else {
    console.log(`You must be 18+ to enter this site`);
}

// ------------------------------------------------------

// with boolean variables
let isStudnet = true;

if(!isStudnet){
    console.log('You are a student');
}
else{
    console.log('You are not a student');
}
// -------------------------------------------------------

// nested if
let hasLicense = false;

if(age >= 16){
    console.log('You are old enough to drive');
    if(hasLicense){
        console.log('You have your license')
    }
    else{
        console.log('You do not have your license yet');
    }
}
else{
    console.log('You must be 16+ to have this license');
}

// ---------------------------------------------------------

// else if statements

if(age >= 18){
    console.log(`You are old enough to enter this site!`)
}
else if(age == 12){
    console.log('You are 12 years old');
}
else if(age < 0){
    console.log('You are not born yet');
}
else {
    console.log(`You must be 18+ to enter this site`);
}

// if we are showing this in the html page, we first read the value from the textbox to age variable, then typecast it to number, then finally we put all these condetions inside the ....onclick = finction(){...if else if statements....}