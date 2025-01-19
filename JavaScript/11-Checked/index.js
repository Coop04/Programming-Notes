// .checked: property that determines the checked state of an html checkbox or radio button element

const myCheckbox = document.getElementById('myCheckbox');
const visaBtn = document.getElementById('visaBtn');
const masterCardBtn = document.getElementById('masterCardBtn');
const paypalBtn = document.getElementById('paypalBtn');
const mySubmit = document.getElementById('mySubmit');
const subResult = document.getElementById('subResult');
const paymentResult = document.getElementById('paymentResult');

mySubmit.onclick = function() {
    if(myCheckbox.checked) {
        subResult.textContent = `You are subscribed`;
        if(visaBtn.checked) {
            paymentResult.textContent = `You are paying with Visa`;
        }
        else if(masterCardBtn.checked){
            paymentResult.textContent = `You are paying with Master Card`;
        }
        else if(paypalBtn.checked) {
            paymentResult.textContent = `You are paying with PayPal`;
        }
        else {
            paymentResult.textContent = `You must select a payment type`;
        }
    }
    else {
        subResult.textContent = `You are not subscribed`;
    }
}