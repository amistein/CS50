<table border="1" style="width: 100%">
    <th>Transaction</th>
    <th>Date</th>
    <th>Time</th>
    <th>Symbol</th>
    <th>Shares</th>
    <th>Price</th>
    
    
    <?php foreach ($rows as $row): 
    
    $date = date("F jS, Y", strtotime($row["date_time"]));
    
    
    $time = new DateTime($row["date_time"], new DateTimeZone('UTC'));
    $time->setTimezone(new DateTimeZone('America/New_York'));
    $time = $time->format('g:i A');
    
    
    
    ?>

    <tr>
        <td><?= $row["transaction"] ?></td>
        <td><?= $date ?></td>
        <td><?= $time ?></td>
        <td><?= $row["symbol"] ?></td>
        <td><?= $row["shares"] ?></td>
        <td><?= $row["price"] ?></td>
    </tr>

    <?php endforeach ?>
    
</table>