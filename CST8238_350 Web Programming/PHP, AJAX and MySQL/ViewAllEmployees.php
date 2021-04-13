<?php
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

  $sql = "SELECT * FROM Employee";

  $employees = mysqli_query($conn, $sql);

  //Close sql connection
  mysqli_close($conn);

?>
<!DOCTYPE html>
<html>
	<head>
		<title>View All Employees</title>
		<link rel="stylesheet" type="text/css" href="stylesheet.css">
	</head>
		<div id="main">
			<div id="header">
				<?php include_once "Header.php"; ?>
				<div id="menu">
					<?php include_once "Menu.php"; ?>
				</div>
			</div>
		  <div id="content">
        <div class="container">
          <h2>Database Data</h2>
          <?php  if (mysqli_num_rows($employees) > 0) { ?>
              <table style="width:100%; padding-bottom: 30px;">
                <tr>
                  <th>First Name</th>
                  <th>Last Name</th>
                  <th>Email Address</th>
                  <th>Phone Number</th>
                  <th>SIN</th>
                  <th>Password</th>
                </tr>
              <?php while($employee = mysqli_fetch_assoc($employees)) { ?>
                <tr>
                  <td><?php echo $employee['FirstName']; ?></td>
                  <td><?php echo $employee['LastName']; ?></td>
                  <td><?php echo $employee['EmailAddress']; ?></td>
                  <td><?php echo $employee['TelephoneNumber']; ?></td>
                  <td><?php echo $employee['SocialInsuranceNumber']; ?></td>
                  <td><?php echo $employee['Password']; ?></td>
                </tr>
            <?php  } ?>
              </table>
            <?php }else{
              echo "<b>No data to display</b>";
            }
          ?>
        </div>
      </div>
      <div id="footer">
        <?php include_once "footer.php"; ?>
      </div>
    </div>
  </body>
</html>
</body>
