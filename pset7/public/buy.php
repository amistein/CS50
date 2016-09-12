<?php

 // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // ensure fields are not empty
        if (empty($_POST["symbol"]))
        {
            apologize("You must specify the symbol of the stock you want to buy.");
        }
        
        else if (empty($_POST["shares"]))
        {
            apologize("You must specify the amount of shares you want to buy.");
        }
        
        // variables for user's cash, stock info, and stock price
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $stock = lookup($_POST["symbol"]);
        $total = $stock["price"] * $_POST["shares"];
        
        // if symbol does not exist
        if ($stock === false)
        {
            apologize("Stock symbol not found!");
        }
        
        // if total cost is more than user's cash
        else if ($total > $cash[0]["cash"])
        {
            apologize("You do not have enough cash!");
        }
        
        // add stock to database if doesn't yet exist or update share amount
        CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?)
        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);
        
        // subtract total cost from user's cash amount
        CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $total, $_SESSION["id"]);
        
        // update history database
        CS50::query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)",
        $_SESSION["id"], 'BUY', $stock["symbol"], $_POST["shares"], $stock["price"]);
        
        // redirect to portfolio
        redirect("/");
    }

?>