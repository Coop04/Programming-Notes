// callback: a function that is passed as an arguement to another function.

// used to handle asynchronous operations: 
//      1. Reading a file 
//      2. Network requests
//      3. Interacting with databases

//      'Hey, when you are done call this next'

// js will not wait around a long time to execue a next function if the current function is consuming more time
function hello() {            
    setTimeout(function() {
        console.log('Hello!')
    }, 3000);
}
function goodBye() {
    console.log('GoodBuy!');
}

hello();      // goodBye is printed first befor hello
goodBye();

// ------------------------------------------

// to ensure that good bye function is executed only after hello we use callback

hello1(goodBye1); // dont use  () for the inner function call

function hello1(callback) {     // use call back inside the first function       
    setTimeout(function() {
        console.log('Hello1!'); 
        callback();             // use callback()
    }, 3000);
}
function goodBye1() {
    console.log('GoodBuy1!');
}

// -------------------------------
function leave(callback) {
    console.log('Leave!');
    callback(); // add callback at the end of the function (but incase when using timeout put the callback() before the end of timeout function)
}

function wait() {
    console.log('Wait!');
}

leave(wait); // leave will print first then wait will be printed

// -------------------------------------

function sum(callback, x, y) {
    let result = x + y;
    callback(result);
}

function displayConsole(result) {
    console.log(result);
}

sum(displayConsole, 10, 20);

function displayDOM(result) {
    document.getElementById('myH1').textContent = result;
}

sum(displayDOM, 10, 20); 