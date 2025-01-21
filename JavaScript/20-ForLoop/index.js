// for loop = repeat some code a limited amount of times

for(let i=3; i >=0; i--) {
    console.log(i);
}

console.log('Happy New Year!!!')
// ---------------------------------------
// continue
for(let i = 1; i<=10; i++) {
    if(i==7) {
        continue;
    }
    else {
        console.log(i);
    }
}
// -----------------------------------------
// break
for(let i = 1; i<=10; i++) {
    if(i==7) {
        break;
    }
    else {
        console.log(i);
    }
}