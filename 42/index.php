<?php
$myfile = fopen("/Applications/MAMP/htdocs/ProjectEulerSolutions/p042_names.txt", "r+") or die("Unable to open file!");
$newfile = fopen("ordered_file.txt", "w");

$string= fread($myfile,filesize("/Applications/MAMP/htdocs/ProjectEulerSolutions/p042_names.txt"));
$array=explode("\",\"",$string);
$array[0] = explode('"',$array[0])[1];

//echo count($array);
$array[count($array)-1]=  explode('"',$array[count($array)-1])[0];

sort($array);
foreach ($array as $key => $val) {
    fwrite($newfile, $val."\n");
}
fclose($myfile);
fclose($newfile);

echo "process completed";
?>