// while loop = repeat some code while some condetion is true

let username = "";

while(username === "" || username === null) {
    console.log('Please enter your name...');
    username = window.prompt('Enter your user name');
}
console.log(`Hello ${username}`);

// -----------------------------------------------------

// do while loop

let username1; // when using do while loop we don't need to assign a value

do {
    console.log('Please enter your name...');
    username = window.prompt('Enter your user name');
}while(username === "" || username === null) 
console.log(`Hello ${username}`);

// ----------------------------------------------

let loggedIn = false;
let username2;
let password;

while(!loggedIn) {
    username2 = window.prompt('Enter your username: ');
    password = window.prompt('Enter your password: ');

    if(username2 === 'myName' && password ==='myPassword') {
        loggedIn = true; // when logged in the condetion becomes false
        console.log('You are logged in!');
    }
    else {
        console.log('Invalid credentials! Please try again');
    }
}

// --------------------------------------------------------------

loggedIn = false;
username2;
password;

do {
    username2 = window.prompt('Enter your username: ');
    password = window.prompt('Enter your password: ');

    if(username2 === 'myName' && password ==='myPassword') {
        loggedIn = true; // when logged in the condetion becomes false
        console.log('You are logged in!');
    }
    else {
        console.log('Invalid credentials! Please try again');
    }
}while(!loggedIn)