<?php
$fp= fopen("abc.txt","w");
fwrite($fp,"Hii this is shubham\n");
fwrite($fp,"Good morning\n");
fclose($fp);

echo "File written successfully<br>";
?>

<?php
$fp = fopen("abc.txt","r");
$content = fread($fp,filesize("abc.txt"));
echo $content;
fclose($fp);
?>

<?php

unlink("abc.txt");
?>