<?php 
    $age = 0;

    if($age>18) {
        echo"Access Granted!";
    }
    elseif ($age==0) {
        echo"You were just born!";
    }
    else {
        echo"Access Denied!";
    }
    // -----------------------------
    echo"<br>";

    $adult = true;

    if($adult) 
        echo"Enter";
    else
        echo"Don't Enter";
?>