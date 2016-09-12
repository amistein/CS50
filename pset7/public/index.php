<?php

    // configuration
    require("../includes/config.php");
    
    // query database for all rows of user's currently owned stocks 
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    // store data to be passed by render() to porfolio.php as array of associative arrays 
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"]
            ];
        }
    }
    
    // query database for user's cash in order to pass to porfolio.php
    $users_cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash = $users_cash[0]["cash"];
   
    
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "cash" => $cash]);

?>
