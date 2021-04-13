<?php
if(!isset($_GET['id'])){
  header("Location: Login.php");
  exit;
}

$id = intval($_GET['id']);

/*Mysql Conection details*/
$host = "localhost";
$username = "updmqx6lgljta";
$password = "cr06mosawztj";
$dbname = "dbecetyorkrj6r";

//Connect to database
$conn = mysqli_connect($host, $username, $password, $dbname);

if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT * FROM Employee WHERE EmployeeID ='".$id."'";

$result = mysqli_query($conn, $sql);

echo "<table>
<tr>
<th>First Name</th>
<th>Last Name</th>
<th>Email Address</th>
<th>Phone Number</th>
<th>SIN</th>
<th>Password</th>
</tr>";
while($employee = mysqli_fetch_array($result)) {
  echo "<tr>";
  echo "<td>" . $employee['FirstName'] . "</td>";
  echo "<td>" . $employee['LastName'] . "</td>";
  echo "<td>" . $employee['EmailAddress'] . "</td>";
  echo "<td>" . $employee['TelephoneNumber'] . "</td>";
  echo "<td>" . $employee['SocialInsuranceNumber'] . "</td>";
  echo "<td>" . $employee['Password'] . "</td>";
  echo "</tr>";
}
echo "</table>";

//Close sql connection
mysqli_close($conn);
?>
