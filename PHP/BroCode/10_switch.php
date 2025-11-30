<?php 
$day = 3;

switch ($day) {
    case 1:
        echo "Monday";
        break;

    case 2:
        echo "Tuesday";
        break;

    case 3:
        echo "Wednesday";
        break;

    case 4:
        echo "Thursday";
        break;

    case 5:
        echo "Friday";
        break;

    default:
        echo "Weekend";
}

echo "<br>";

$color = "blue";

switch ($color) {
    case "red":
        echo "Stop!";
        break;

    case "green":
        echo "Go!";
        break;

    case "blue":
        echo "Calm and cool.";
        break;

    default:
        echo "Unknown color.";
}

echo "<br>";

// multiple cases executed the same
$fruit = "apple";

switch ($fruit) {
    case "apple":
    case "banana":
    case "mango":
        echo "This is a fruit.";
        break;

    default:
        echo "Not a fruit.";
}

?>