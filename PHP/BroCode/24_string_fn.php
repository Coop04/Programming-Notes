<?php 
    $username = "Aswanth Satheesan";
    $phone = "123-456";
    $user = "Sheldon Lee Cooper";

    $username = strtolower($username);
    // $username = strtoupper($username);
    // $username = trim($username); // remove whitespaces before / after the string
    // $username = str_pad($username,30,"$"); 
    // $phone = str_replace("-","",$phone); 
    // $username = strrev($username);
    // $username = str_shuffle($username);
    $eq = strcmp($username, "aswanth satheesan"); // -1 if 2nd str is preceeding
                                                  // 0 if same
                                                  // 1 if 2nd str is proceeding (in front) 
    $len = strlen($username);

    $pos = strpos($username,"h");

    $sub = substr($username, 8,17); // last index exclusive
    $sub = substr($username, 8); // (same as above) last index exclusive

    $fullname = explode(" ",$user);

    $fullname_str = implode("-",$fullname);

    

    echo $username;
    echo"<br><br>";
    echo $phone;
    echo"<br><br>";
    echo $eq; 
    echo"<br><br>";
    echo $len; 
    echo"<br><br>";
    echo $pos; 
    echo"<br><br>";
    echo $sub; 
    echo"<br><br>";
    print_r($fullname); 
    echo"<br>";
    print_r($fullname_str);
    echo"<br><br>"; 

?>