<?php 
    include("database.php");

    // $sql = "SELECT * FROM users WHERE user = 'Spongebob'";
    $sql = "SELECT * FROM users";
    
    $result = mysqli_query($conn,$sql); //now result is an object
    // somewhere within result there is an associative array

    if(mysqli_num_rows($result)>0) {
        while($row = mysqli_fetch_assoc($result)) { // to retrieve multiple users
            echo $row["id"]. "<br>" ;
            echo $row["user"]. "<br>" ;
            echo $row["reg_date"]. "<br>" ;
            echo "<br><br>";
        }
        
    }
    else 
        echo "No user found";

    mysqli_close($conn);
?>