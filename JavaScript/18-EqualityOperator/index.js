// assignment operator: =
// comparison operator: == (compares if values are equal)
// strict equality operator: === (compare if values & datatype are equal)
// inequality operator: !=
// strict inequality operator: !==

const PI = 3.14;

if(PI == '3.14') {
    console.log('That is Pi (comparison operator)');
}
else {
    console.log('This is not Pi');
}
// --------------------------------------------

if(PI === '3.14') {
    console.log('That is Pi (comparison operator)');
}
else {
    console.log('This is not Pi');
}
// -------------------------------------------

if(PI !== '3.14') {
    console.log('This is not Pi');
}
else {
    console.log('That is Pi (comparison operator)');
}