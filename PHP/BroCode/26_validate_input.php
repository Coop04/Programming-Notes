<!-- validation  returns empty string if not passed-->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="26_validate_input.php" method="post">
        Username: <input type="text" name="username"><br>
        Age:<input type="text" name="age"><br>
        Email:<input type="email" name="email"><br>
        <input type="submit" name="login" value="login">
    </form>
</body>
</html>

<?php 
    if(isset($_POST["login"])) {
        
        $age = filter_input(INPUT_POST,"age",FILTER_VALIDATE_INT);
        // FILTER_VALIDATE_EMAIL to validate email

        if(empty($age)) {
            echo "That no. is not valid";
        }
        else {
            echo "You are $age years old";
        }

    }
?>