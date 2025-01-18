// How tp accept user input

// 1. Easy way: window prompt
// 2. Professional way: HTML textbox


// Easy way

let username1;
username1 = window.prompt("What's your username");
console.log(username1);

// ---------------------------------------------------

// Professional way
// make changes in the html file then,

let username2;
document.getElementById('mySubmit').onclick = function(){
    username2 = document.getElementById("myText").value;
    // console.log(username); // prints the entered text into the console 
    document.getElementById('myH1exp4').textContent=`Hello ${username2}`;
}