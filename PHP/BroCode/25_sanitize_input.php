<!-- Sanitize and validate user input whenever possible -->
<!-- Sanitization strips certain character of user input -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="25_sanitize_input.php" method="post">
        Username: <input type="text" name="username"><br>
        Age:<input type="text" name="age"><br>
        Email:<input type="email" name="email"><br>
        <input type="submit" name="login" value="login">
    </form>
</body>
</html>

<?php 
    if(isset($_POST["login"])) {
        $user = filter_input(INPUT_POST, "username",FILTER_SANITIZE_SPECIAL_CHARS);
        echo "Hello {$user}";

        //<script>alert('hacked')</script> if you type this it will only print (won't execute)
        
        // if you need to sanitize all charecters besides numbers use FILTER_SANITIZE_NUMBER_INT
        $age = filter_input(INPUT_POST, "age", FILTER_SANITIZE_NUMBER_INT);
        // if I type in sffd65d it will only take 65 as age
        echo "You are {$age} years old";

        $email = filter_input(INPUT_POST,"email",FILTER_SANITIZE_EMAIL);
        echo $email;

    }
?>