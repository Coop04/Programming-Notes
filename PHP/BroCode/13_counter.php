<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="13_counter.php" method="post">
        Enter a no. to count to: <input type="text" name="count"><br>
        <input type="submit" value="Count">
    </form>
</body>
</html>
<?php 
    if($_SERVER["REQUEST_METHOD"]=="POST") {
        $count = $_POST["count"];
        for($i=1;$i<=$count;$i++) {
            echo $i."<br>";
        }
    }
    
?>