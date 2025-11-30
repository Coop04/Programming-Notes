<?php 
    $name = "Aswanth";
    $food = "pizza";

    $num = 4;
    $users = 2;

    $gpa = 2.5;
    $price = 4.99;

    $employed = true;
    $online = false;
    $online1 = true;

    $total = null;

    echo "Hello {$name}<br>";
    echo "You like {$food}<br>";
    
    echo "My favourate no. is {$num} <br>";
    echo "There are {$users} users online<br>";

    echo "Your GPA is {$gpa}<br>";
    echo "Your pizza is \${$price}<br>";

    echo "Online status: {$online} <br>"; // if boolean is false doesnt show anything
    echo "Online status: {$online1} <br>"; // if true shows 1

    echo "You have ordered {$num} {$food}s<br>";
    $total = $num * $price;
    echo "Total amount: \${$total}<br>";
?>