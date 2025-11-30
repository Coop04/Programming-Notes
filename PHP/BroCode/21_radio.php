<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="21_radio.php" method="post">
        <input type="radio" name="card" value="Visa">
        Visa <br>
        <input type="radio" name="card" value="MasterCard">
        Master Card <br>
        <input type="radio" name="card" value="American Express">
        American Express <br>
        <input type="submit" name="confirm" value="Confirm" id="">
    </form>
</body>
</html>
<?php 
    if(isset($_POST["confirm"])) {

        $credit = null;

        if(isset($_POST["card"])) {
            $credit = $_POST["card"];
            
        }
        if($credit == "Visa") {
            echo "You Selected Visa";
        }
        elseif($credit == "MasterCard") {
            echo "You Selected MasterCard";
        }
        elseif($credit == "American Express") {
            echo "You Selected American Express";
        }
        else {
            echo "Please select a card";
        }
    }

?>