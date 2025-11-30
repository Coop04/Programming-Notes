<!-- Order page for a restraunt -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="5_order_page.php" method="post">
        Quantity: <input type="number" name="quantity"><br><br>
        <input type="submit" value="Order Total">
    </form>
</body>
</html>
<?php 
    $item = "pizza";
    $price = 5.99;
    $quantity = $_POST["quantity"]; // caching to local variable
    $total = $quantity * $price;

    echo "Your have ordered {$quantity} x {$item}s<br>";
    echo "Total amount: \${$total}";
    
?>