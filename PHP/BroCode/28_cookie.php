<?php 
    // cookie = Information about a user stored in usersweb browser
    //          Targeted advertisements, browsing preferences and other non sensitive data

    setcookie("fav_food", "pizza", time() - (86400 *2), "/"); // last parameter is file path: default /
    setcookie("fav_drink", "coffie", time() + (86400 *3), "/"); 

    // to delete a cookie set time to -ve value
    setcookie("fav_dessert", "ice cream", time() - 0, "/"); 

    foreach($_COOKIE as $key => $value) {
        echo "{$key} = {$value}<br>";
    }

    if(isset($_COOKIE["fav_food"])) {
        echo "Buy some {$_COOKIE["fav_food"]}!!!<br>";
    }
    else 
        echo "I dont know your fav_food";
?>
