<?php 
    // Associative array =  an array made of key => value pairs

    $capitals = array("USA"=>"Washington DC",
                      "Japan"=>"Kyoto",
                      "South Korea" => "Seol",
                      "India"=>"Delhi");

    print_r($capitals);

    echo "<br><br>";

    echo $capitals["Japan"]; // gives the value

    echo "<br><br>";

    $capitals["USA"] = "Las Vegas"; // updating value

    $capitals["China"] = "Beijing";

    array_pop($capitals); // pops last value

    array_shift($capitals); // removes first element

    foreach($capitals as $c=>$c_value) {
        echo "{$c} => {$c_value}<br>";
    }

    echo "<br><br>";

    $keys = array_keys($capitals); // to get the keys
    foreach($keys as $c=>$c_value) {
        echo "{$c} => {$c_value}<br>";
    }

    echo "<br><br>";

    $values = array_values($capitals); // to get the keys
    foreach($values as $c=>$c_value) {
        echo "{$c} => {$c_value}<br>";
    }

    echo "<br><br>";

    $flip = array_flip($capitals); // flips the keys and values 
    print_r($flip);

    echo "<br><br>";

    $rev = array_reverse($capitals); // reverse the array 
    print_r($rev);

    echo "<br><br>";

    asort($capitals); // sorts by values (ascending order)
    print_r($capitals);

    echo "<br><br>";

    arsort($capitals); // sorts by values (descending order)
    print_r($capitals);

    echo "<br><br>";

    ksort($capitals); // sorts by keys (ascending order)
    print_r($capitals);

    echo "<br><br>";

    krsort($capitals); // sorts by keys (descending order)
    print_r($capitals);

    echo "<br><br>";
    // --------------------------

    echo count($capitals); // to count key value pairs

?>