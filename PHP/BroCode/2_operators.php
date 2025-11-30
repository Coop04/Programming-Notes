<?php 

    // Arithmetic Operators
    $x = 10;
    $y = 2;
    $z = null;

    // $z = $x + $y;
    // $z = $x - $y;
    // $z = $x * $y;
    // $z = $x / $y;
    // $z = $x ** $y;
    $z = $x % $y;

    echo $z;

    // Increment/Decrement Operators
    $counter = 0;
    $counter++;
    echo "<br>".$counter."<br>";
    $counter--;
    echo $counter."<br>";
    $counter+=5;
    echo $counter."<br>";
    $counter-=4;
    echo $counter."<br>";

    // Operator precendece -> (), **, */%, +-
    $total = 1+2-3*4/5**6;
    echo $total;


?>