<?php
    
    // configuration
    require("../includes/config.php");
    
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // get stock info
        $stock = lookup($_POST["symbol"]);
        
        // if stock is valid
        if ($stock != false)
        {
            // render page with quote info providing stock info values 
            render("d_quote.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
        }
        
        // if stock symbol doesn't exist
        else
        {
            apologize("Stock symbol not found.");
        }
    }
    
?>