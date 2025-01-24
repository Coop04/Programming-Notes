// Variable scope = where a variable is recognised and accessible (local vs global)

let x = 4;   // global scope

// let x = 1; You can't reuse same variable names as long as they are in different scopes

// ----------------------------------------------------------

function function1() {
    let x = 1;               // local scope: variable declared within {}
    console.log(x);
}
function function2() { 
    let x = 2;               // this is possible since they are in different scopes.
    console.log(x);
}
function function3() {
    console.log(x);         // global variables can be accessed from anywhere
}

function1();
function2();
function3();
