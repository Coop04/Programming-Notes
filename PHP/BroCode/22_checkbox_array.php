<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="22_checkbox.php" method="post">
        <input type="checkbox" name="food[]" value="Pizza">
        Pizza <br>
        <input type="checkbox" name="food[]" value="Hamburger">
        Hamburger <br>
        <input type="checkbox" name="food[]" value="Hotdog">
        Hotdog <br>
        <input type="checkbox" name="food[]" value="Taco">
        Taco <br>
        <input type="submit" name="submit"  id="">
    </form>
</body>
</html>
<?php 
    if(isset($_POST["submit"])) {
        $food = $_POST["food"];
        foreach($food as $f) {
            echo $food."<br>";
        }
    }
?>