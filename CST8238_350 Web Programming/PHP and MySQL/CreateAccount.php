<?php
//Start a php session
session_start();

/*Mysql Conection details*/
$host = "localhost";
$username = "updmqx6lgljta";
$password = "cr06mosawztj";
$dbname = "dbecetyorkrj6r";

//Connect to database
$conn = mysqli_connect($host, $username, $password, $dbname);

if (!$conn) {
  die("Connection failed: " .mysqli_connect_error());
}

//Create database table if it does not exist
$sql = "CREATE TABLE IF NOT EXISTS `Employee` (
	`EmployeeId` INT NOT NULL AUTO_INCREMENT,
	`FirstName` VARCHAR(50),
	`LastName` VARCHAR(50),
	`EmailAddress` VARCHAR(255),
	`TelephoneNumber` VARCHAR(20),
	`SocialInsuranceNumber` VARCHAR(11),
	`Password` VARCHAR(50),
	PRIMARY KEY (`EmployeeId`)
) ENGINE=InnoDB;
";

$sqlError = "";

if ( !mysqli_query($conn, $sql) ){
  $sqlError = "Error creating table: " . mysqli_error($conn);
}

//variables for form
$fNameErr = $lNameErr = $emailErr = $phoneErr = $sinErr = $passErr = "";
$firstName = $lastName = $email = $phone = $sin = $password = "";
$flag = 0;//check if validation passed, 1 of not
//Check that form was submited
if ($_SERVER["REQUEST_METHOD"] == "POST") {

  //validate the FirstName
  if(empty($_POST['FirstName'])){
    $fNameErr = "Missing First Name";
    $flag = 1;
  }else{
    $firstName = test_input($_POST['FirstName']);
  }

  //validate the LastName
  if(empty($_POST['LastName'])){
    $lNameErr = "Missing Last Name";
    $flag = 1;
  }else{
    $lastName = test_input($_POST['LastName']);
  }

  //validate the EmailAddress
  if(empty($_POST['EmailAddress'])){
    $emailErr = "Missing email address";
    $flag = 1;
  }else{
    $email = test_input($_POST['EmailAddress']);
  }

  //validate TelephoneNumber
  if(empty($_POST['TelephoneNumber'])){
    $phoneErr = "Missing Phone Number";
    $flag = 1;
  }else{
    $phone = test_input($_POST['TelephoneNumber']);
  }

  //validate SocialInsuranceNumber
  if(empty($_POST['SocialInsuranceNumber'])){
    $sinErr = "Missing SIN";
    $flag = 1;
  }else{
    $sin = test_input($_POST['SocialInsuranceNumber']);
  }

  //validate Password
  if(empty($_POST['Password'])){
    $passErr = "Missing Password";
    $flag = 1;
  }else{
    $password = test_input($_POST['Password']);
  }

  if($flag == 0){
    //save to database
    $sql = "INSERT INTO Employee (FirstName, LastName, EmailAddress,TelephoneNumber, SocialInsuranceNumber, Password)
    VALUES ('$firstName', '$lastName', '$email', '$phone', '$sin', '$password')";

    //check if successful
    if (mysqli_query($conn, $sql)) {
      //save to session
      $_SESSION["FirstName"] = $firstName;
      $_SESSION["LastName"] = $lastName;
      $_SESSION["EmailAddress"] = $email;
      $_SESSION["TelephoneNumber"] = $phone;
      $_SESSION["SocialInsuranceNumber"] = $sin;
      $_SESSION["Password"] = $password;

      header("Location: ViewAllEmployees.php");
      exit;
    }else{
      $sqlError = "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
  }
}

//Close sql connection
mysqli_close($conn);

//Function to validate input fields
function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Create Account</title>
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
          <div class="errors">
          <?php
            if(!empty($sqlError)){
              echo "<p>".$sqlError."</p>";
            }

            if($flag == 1) {
              echo "<p>".$fNameErr ."</p>";
              echo "<p>" .$lNameErr . "</p>";
              echo "<p>" .$emailErr . "</p>";
              echo "<p>" .$phoneErr . "</p>";
              echo "<p>" .$sinErr . "</p>";
              echo "<p>" . $passErr . "</p>";
            }
          ?>
          </div>
          <h2>Create your new account<h2>
          <form method="post">
            <label for="FirstName">First Name</label>
          	<input name="FirstName" type="text" value=""/>
            <br/>
            <label for="LastName">Last Name</label>
            <input name="LastName" type="text" value=""/>
            <br/>
            <label for="EmailAddress">Email Address</label>
            <input name="EmailAddress" type="email">
            <br/>
            <label for="TelephoneNumber">Phone Number</label>
            <input name="TelephoneNumber" type="text" value="" />
            <br/>
            <label for="SocialInsuranceNumber">SIN</label>
            <input name="SocialInsuranceNumber" type="text" value="" />
            <br/>
            <label for="Password">Password</label>
            <input name="Password" type="password" />
            <br/>
            <input type="submit" value="Submit Information"/>
          </form>
        </div>
      </div>
      <div id="footer">
        <?php include_once "Footer.php"; ?>
      </div>
    </div>
  </body>
</html>
</body>
