<?php
    // hashing = transforming sensitive data (password) 
    // into letters, numbers and/or symbols via a 
    // mathematical process.(similar to encryption).
    // Hides the original data from 3rd parties.

    $password = "pizza123";

    $hash = password_hash($password, PASSWORD_DEFAULT);

    echo $hash;

    if(password_verify("pizza123", $hash)) { // returns true if there is a match
        echo "<br>You are logged in";
    }
    else
        echo "<br>incorrect password";

?>