// Dice Roller Program

function rollDice() {
    const numOfDice = document.getElementById('numOfDice').value;
    const diceResult = document.getElementById('diceResult');
    const diceImages = document.getElementById('diceImages');
    const values = [];
    const images = [];

    for(let i=0; i<numOfDice; i++) {
        const value = Math.round(Math.random() * 5)+1;
        values.push(value);
        images.push(`<img src="dice_images/${value}.png" alt="Dice: ${value}">`);
    }
    diceResult.textContent = `Dice: ${values.join(', ')}`;
    diceImages.innerHTML = images.join('');
}