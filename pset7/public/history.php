<?php

    // configuration
    require("../includes/config.php");

    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    
    // render history
    render("history_table.php", ["title" => "History", "rows" => $rows]);

?>