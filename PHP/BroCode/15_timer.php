<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="15_timer.php" method="post">
        <input type="submit" name="start" value="START"><br><br>
        <input type="submit" name="stop" value="STOP"><br>
    </form>
</body>
</html>

<?php 
$counter = 0;
$running = true;
    if(isset($_POST["start"])) {
        while($running) {
            if(isset($_POST["stop"])) {
                $running = false; // or break;
            }
            echo $counter."<br>";
            $counter++;
        }
    }

?>