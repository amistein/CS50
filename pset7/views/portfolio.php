<table border="1" style="width: 100%">
    <th>Symbol</th>
    <th>Name</th>
    <th>Shares</th>
    <th>Price</th>
    <th>Total</th>
    
    
    <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
        <td><?= $position["shares"] * $position["price"] ?></td>
    </tr>

    <?php endforeach ?>
    
    <tr>
        <td colspan="4">CASH</td>
        <td><?= $cash ?></td>
    </tr>
</table>