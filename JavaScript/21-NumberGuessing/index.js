// Number Guessing Game

const minNum = 1;
const maxNum = 100;
const answer = Math.round(Math.random() * (maxNum - minNum)) + minNum;

let attempts = 0;
let guess;
let running = true;

while(running) {
    guess = window.prompt(`Guess a number between ${minNum} & ${maxNum}`);
    guess = Number(guess);

    if(isNaN(guess)) {
        window.alert('Please enter a  valid number');
    }
    else if(guess < minNum || guess > maxNum) {
        window.alert(`Enter a valid number`);
    }
    else {
        attempts++;
        if(guess < answer) {
            window.alert('Too low! Try again!');
        }
        else if(guess > answer) {
            window.alert('Too high! Try again!');
        }
        else {
            window.alert(`Correct!. It took you ${attempts} attempts.`);
            running = false;
        }
    }
}

