<?php 
    // && is and 
    // || is or
    // ! is not
    $temp = 25;
    $cloudy = true;

    if($temp>=0 && $temp<=30) {
        echo "The weather is good";
    }
    else {
        echo "The weather is bad";
    }

    echo "<br>";

    if(!$cloudy) {
        echo "Good weather";
    }
    else {
        echo "bad weather";
    }
?>