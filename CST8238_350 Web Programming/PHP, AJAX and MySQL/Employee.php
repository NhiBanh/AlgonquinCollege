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
		<title>Employee</title>
		<link rel="stylesheet" type="text/css" href="stylesheet.css">
    <script>
      function showEmployee(info) {
        if (info == "") {
          document.getElementById("employeeData").innerHTML = "<b>Employee information will be displayed in this section</b>";
          return;
        } else {
          var xmlhttp = new XMLHttpRequest();
          xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              document.getElementById("employeeData").innerHTML = this.responseText;
            }
          };
          xmlhttp.open("GET","GetEmployee.php?id="+info,true);
          xmlhttp.send();
        }
      }
    </script>
	</head>
		<div id="main">
			<div id="header">
				<?php include_once "Header.php"; ?>
				<div id="menu">
					<?php include_once "Menu.php"; ?>
				</div>
			</div>
		  <div id="content">
        <form>
          <select name="employee" onchange="showEmployee(this.value)">
            <option value="" disabled selected>Select your option</option>
            <?php
              foreach ($employees as $employee) {
                echo '<option value="'. $employee['EmployeeId'] . '"> '. $employee['FirstName'] . ' ' .   $employee['LastName'] . '</option>';
              }
            ?>
          </select>
        </form>
        <br/>
        <div id="employeeData"><b>Employee information will be displayed in this section</b></div>
      </div>
      <div id="footer">
        <?php include_once "footer.php"; ?>
      </div>
    </div>
  </body>
</html>
</body>
