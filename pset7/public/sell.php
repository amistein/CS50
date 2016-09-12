<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // query database for symbols of all stocks currently owned by user
        $stocks = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        // render form
        render("sell_form.php", ["title" => "Sell", "stocks" => $stocks]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // query database to determine amount of shares owned by user
        $row = CS50::query("SELECT * FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        // lookup current price to determine credit owed to user
        $lookup = lookup($_POST["symbol"]);
        $credit;
        if ($lookup !== false)
        {
            $credit = $lookup["price"] * $row[0]["shares"];
        }
        
        // delete stock from database
        CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        // add credit to user's cash amount
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $credit, $_SESSION["id"]);
        
        // update history database
        CS50::query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)",
        $_SESSION["id"], 'SELL', $lookup["symbol"], $row[0]["shares"], $lookup["price"]);
        
        // redirect to portfolio
        redirect("/");
    }

?>