<?php 
    declare(strict_types=1);// necessary if you need to strictly specify parameter type

    function a(string $x) { // to strictly specify types of parameters
        if($x=="a") {
            echo "It's a";
        }
        else {
            echo "It's something else";
        }
    }

    a("a"); // shows error if not a string

    echo"<br><br>";

    function happy_birthday($you,$x) {
        echo "Happy Birthday dear {$you}!<br>";
        echo "You are {$x} years old!";
    }
    happy_birthday("Kuttu", 5);

    echo"<br><br>";

    function oddeven($x){
        if($x%2==0) {
            echo "Even";
        }
        else {
            echo "Odd";
        }
    }
    oddeven(3);

    echo"<br><br>";

    function add(int $a, int $b) : int { // to strictly return a type
    return $a + $b;
    }

    echo add(3,4); 

?>