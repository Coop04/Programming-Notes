<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    This is the home page <br>
    <form action="29_home.php" method="post">
        <input type="submit" name="logout" value="logout">
    </form>
</body>
</html>
<?php
    // here we are accessing the session credential designed in 29_session.php
    echo "<br>".$_SESSION["username"]."<br>".$_SESSION["password"]; 
    
    if(isset($_POST["logout"])) {
        session_destroy(); // to destroy the session
        header("Location: 29_session.php");
    }
?>