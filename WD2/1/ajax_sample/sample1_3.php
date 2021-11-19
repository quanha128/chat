<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
</head>
<body>
  <h1>INIAD Web design 2</h1>
  <span id="number">number = </span>
  <?php
    $sum = 0;
    for ($i = 1; $i <= 10; $i++) { $sum += $i; };
    print $sum;
  ?>
</body>
</html>
