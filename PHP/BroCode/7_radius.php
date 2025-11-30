<?php 
    $area = $circ = $vol = $r = null;

    if($_SERVER["REQUEST_METHOD"]=="POST") {
        $r = $_POST["radius"];
        if(isset($_POST["area"])) {
            $area = pi()*$r**2;
            $area = round($area, 2);
        }
        if(isset($_POST["circumference"])) {
            $circ = pi()*$r*2;
            $circ = round($circ, 2);
        }
        if(isset($_POST["volume"])) {
            $vol = (4/3)*pi()*$r**3;
            $vol = round($vol,2);
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="7_radius.php" method="post">
        Radius: <input type="text" name="radius" value="<?php echo $r ?>"><br>
        <input type="submit" name="area" value="Area">
        <span><?php echo($area!= null)?"Area: {$area}":"" ?></span>
        <br><input type="submit" name="circumference" value="Circumference">
        <span><?php echo($circ!=null)?"Circumference: {$circ}":"" ?></span>
        <br><input type="submit" name="volume" value="Volume">
        <span><?php echo($vol!=null)?"Volume: {$vol}": "" ?></span>
    </form>
</body>
</html>

