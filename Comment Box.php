<!-- Comment Box basic using PHP, HTMl and MySQL -->
<?php
mysql_connect("localhost","root","");
mysql_select_db("cmtdb");
error_reporting(E_ALL ^ E_NOTICE);
$notify = "";
$name=$_POST['name'];
$comment=$_POST['comment'];
$submit=$_POST['submit'];
if(isset($_POST['notify_box'])){ $notify = $_POST['notify_box']; }
$dbLink = mysql_connect("localhost", "root", "");
    mysql_query("SET character_set_client=utf8", $dbLink);
    mysql_query("SET character_set_connection=utf8", $dbLink);
 
if($submit)
{
    if($name&&$comment)
    {
        $insert=mysql_query("INSERT INTO comment (name,comment) VALUES ('$name','$comment') ");
    }
    else
    {
        echo "please fill out all fields";
    }
}

$dbLink = mysql_connect("localhost", "root", "");
mysql_query("SET character_set_results=utf8", $dbLink);
mb_language('uni');
mb_internal_encoding('UTF-8');
 
$sql = "SELECT * FROM comment";
$getquery = mysql_query($sql);
?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Comment box</title>
<style type="text/css">
body { margin: auto 48px; }
</style>
</head>
<body>
    <div>
        <table id="commentTable">
            <colgroup>
                <col width="25%"/>
                <col width="75%"/>
            </colgroup>
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Comment</th>
                </tr>
            </thead>
            <tbody>
<?php
while($row = mysql_fetch_array($getquery)) {
    echo '<td>' . $row['name'] . '</td>';
    echo '<td>' . $row['comment'] . '</td>';
}
?>
            </tbody>
        </table>
    </div>
    <form action="comment.php" method="POST">
        <colgroup>
            <col widht="25%" style="vertical-align:top;"/>
            <col widht="75%" style="vertical-align:top;"/>
        </colgroup>
        <table>
            <tr>
                <td><label for="name">Name</label></td>
                <td><input type="text" name="name"/></td>
            </tr>
            <tr>
                <td><label for="comment">Comment:</label></td>
                <td><textarea name="comment" rows="10" cols="50"></textarea></td>
            </tr>
            <tr><td colspan="2"><input type="submit" name="submit" value="Comment"></td></tr>
        </table>
    </form>
</body>
</html>
