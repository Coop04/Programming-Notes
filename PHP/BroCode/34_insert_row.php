<?php 
    include("database.php");

    $username = "Magnus";
    $password = "hohoho";
    $hash = password_hash($password, PASSWORD_DEFAULT);

    $sql = "INSERT INTO users (user, password)
            VALUES ('$username', '$hash')";

    try {
        mysqli_query($conn, $sql);
        echo "user is now registered";
    }
    catch(mysqli_sql_exception) {
        echo "Could not register user";
    }

    mysqli_close($conn);
?>