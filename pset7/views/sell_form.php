<form action="sell.php" method="post">
    <fieldset>
    <div class="form-group">
        <label for="sel">Select the stock you want to sell:<br></label>
    </div>
    <div class="form-group">
        <select class="form-control" name="symbol" id="sel">
        
            <?php foreach ($stocks as $stock): ?>
    
            <option><?= $stock["symbol"] ?></option>
    
            <?php endforeach ?>
        </select>
    </div>        
        
    <div class="form-group">
        <button class="btn btn-success" type="submit">Sell</button>
    </div>
    </fieldset>
</form>
