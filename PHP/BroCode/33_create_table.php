<?php 
    include("database.php");

    $sql = "CREATE TABLE new_users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL)";

    try {
        mysqli_query($conn, $sql);
        echo "Table added!";
    }
    catch(mysqli_sql_exception) {
        echo "Table wasn't created ><";
    }

    mysqli_close($conn);
?>