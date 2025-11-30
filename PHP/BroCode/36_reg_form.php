<?php
    include("database.php");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="<?php htmlspecialchars($_SERVER["PHP_SELF"])?>" method="post">
        <h2>Welcome to Fakebook!</h2><br>
        Username: <input type="text" name="username" id=""><br>
        Password: <input type="password" name="password" id=""><br>
        <input type="submit" name="submit" value="Register" id="">
    </form>
</body>
</html>
<?php

    if($_SERVER["REQUEST_METHOD"]=="POST") {
        $username = filter_input(INPUT_POST,"username",FILTER_SANITIZE_SPECIAL_CHARS);
        $password = filter_input(INPUT_POST,"password",FILTER_SANITIZE_SPECIAL_CHARS);
    }

    if(empty($username)) {
        echo "Enter a valid name";
    }
    elseif(empty($password)) {
        echo "Enter a valid password";
    }
    else {
        $hash = password_hash($password,PASSWORD_DEFAULT);
        $sql = "INSERT INTO users (user, password)
                VALUES ('$username','$hash')";
        
        try {
            mysqli_query($conn, $sql);
            echo "Registered Successfully";
        }
        catch(mysqli_sql_exception) {
            echo "User name already taken";
        }
    }

    mysqli_close($conn);
?>