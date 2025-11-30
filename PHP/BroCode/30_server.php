
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="<?php htmlspecialchars($_SERVER["PHP_SELF"]) ?>" method="post"> <!-- PHP_SELF: contains the file path for the current file  -->
        <!-- by this way even if we rename the file the file path will change automatically -->
         <!-- place PHP_SELF inside htmlspecialchars() to sanitize (to avoid cross eyed scripts) -->
        Username: <input type="text" name="username" id=""><br>
        <input type="submit" name="Submit" id="">
    </form>
</body>
</html><?php
    // $_SERVER = Super GLobal Variable that contains header paths, add script locations.
    // The entries in this are created by the web server.
    // Shows nearly everything you need to know about the current web page env.
  
    // foreach($_SERVER as $key => $value) {
    //     echo "{$key} = {$value}<br>";
    // }

    // 2nd : REQUEST_METHOD

    if($_SERVER["REQUEST_METHOD"]=="POST") {
        echo "Hello";
    }
?>