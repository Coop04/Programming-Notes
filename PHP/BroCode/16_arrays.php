<?php 

    // 1st way
    $food[] = "apple";
    $food[] = "orange";
    $food[] = "kiwi";
    $food[] = "grape";

    print_r($food);
    echo "<br><br>";
    var_dump($food); // better for debugging
    echo "<br><br>";

    foreach($food as $i) {
        echo "{$i} <br>";
    }

    echo "<br>";

    // 2nd way
    $alpha = array("a","b","c","d");
    print_r($alpha);
    echo "<br>".$alpha[2]; // accessin element

    echo "<br><br>";
    // -------------------------------------------------

    $food[0] = "pineapple";
    print_r($food);

    echo "<br><br>";

    array_push($food,"guava","banana");  // add to end
    print_r($food);

    echo "<br><br>";

    $f = array_pop($food); // remove from end (also returns the element)
    echo $f;

    echo "<br><br>";

    array_unshift($food,"apple"); // add to front
    print_r($food);

    echo "<br><br>";

    $a = array_shift($food); // remove from front (also return the element)
    print $a."<br>";
    print_r($food);

    echo "<br><br>";

    $reversed = array_reverse($food); // reversing the array
    print_r($reversed);

    echo "<br><br>";

    echo count($food); // to count no. of elements
    echo "<br><br>";

    echo sizeof($food); // same as count
    echo "<br><br>";


    // -------------------------------------------------
    // Sorting
    sort($food); // ascending order sort
    print_r($food);

    echo "<br><br>";

    rsort($food); // descending order sort (reverse order)
    print_r($food);
    // --------------------------------------------


?>