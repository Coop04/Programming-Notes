<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="18_capitals.php" method="post">
        Enter Country Name: <input type="text" name="country">
        <br><input type="submit" name="capital" value="Find Capital" id="">
    </form>
</body>
</html>

<?php 
    $capitals = array("USA"=>"Washington DC",
                      "Japan"=>"Kyoto",
                      "South Korea" => "Seol",
                      "India"=>"Delhi");
    
    $country = $_POST["country"];

    if($_SERVER["REQUEST_METHOD"]=="POST")
        echo "<br>";
        echo $capitals[$country];
?>