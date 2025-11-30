<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="6_math_fns.php" method="post">
        x: <input type="text" name="x"><br><br>
        y: <input type="text" name="y"><br><br>
        z: <input type="text" name="z"><br><br>
        <input type="submit" value="Total">
    </form>
    
</body>
</html>

<?php 
    $x = $_POST["x"];
    $total = null;

    // $total = abs($x);
    // $total = round($x);
    // $total = floor($x);
    // $total = ceil($x);
    // $total = sqrt($x);
    // $total = pow($x,$y);
    // $total = max($x,$y,$z);
    // $total = min($x,$y,$z);
    // $total = pi(); // prints pi value with decimal points
    // $total = rand(); // random no.
    // $total = rand(1,6); // random no. between 1 & 6 (1 & 6 included)


    echo $total;
?>