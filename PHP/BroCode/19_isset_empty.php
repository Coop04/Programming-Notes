<?php 
    // isset() = Returns TRUE if a variable is declared and not null
    // empty() = Returns TRUE if a variable is not declared, false, null, ""
    
    $username = "Aswanth";
    $username1 = "";
    $username2 = null;

    echo isset($username); // outputs  1
    echo isset($username2); // outputs  nothing
    // still outputs 1 for $username values like true, false, ""
    // ie, only shows nothing is $username = null

    echo "<br><br>";

    if(isset($username1)) {
        echo "This variable is set";
    }
    else {
        echo "This variable is not set";
    }

    // ---------------------------------------------

    echo "<br><br>";
    
    if(empty($username2)) {
        echo "This variable is empty";
    }
    else {
        echo "This variable is not empty";
    }
    // returns empty for values like "", false, null

?>
