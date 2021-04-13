<?php
  session_start();

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
  $loginErr = "";
  $emailErr = "";
  $passErr = "";
  $email = "";
  $password = "";
  $flag = 0;
  if ($_SERVER["REQUEST_METHOD"] == "POST") {

    if(empty($_POST['EmailAddress'])){
      $emailErr = "Missing email address.";
      $flag = 1;
    }else{
      $email = test_input($_POST['EmailAddress']);
    }

    if(empty($_POST['Password'])){
      $passErr = "Missing email address.";
      $flag = 1;
    }else{
      $password = test_input($_POST['Password']);
    }

    $sql = "SELECT * FROM Employee WHERE EmailAddress=? AND Password=?";
    $login = $conn->prepare($sql);
    $login->bind_param("ss",  $email, $password);

    //Run the query
    $login->execute();

    //Get result of query
    $result = $login->get_result();

    //Get data from query
    $user = $result->fetch_assoc();

    //Check if invalid Credentials
    if(empty($user)){
      $loginErr = "Invalid Credentials please try again!!!";
    }else{//valid Credentials
      //Set session data
      $_SESSION["FirstName"] = $user["FirstName"];
      $_SESSION["LastName"] = $user["LastName"];
      $_SESSION["EmailAddress"] = $user["EmailAddress"];
      $_SESSION["TelephoneNumber"] = $user["TelephoneNumber"];
      $_SESSION["SocialInsuranceNumber"] = $user["SocialInsuranceNumber"];
      $_SESSION["Password"] = $user["Password"];

      //redirect to ViewAllEmployees
      header("Location: ViewAllEmployees.php");
      exit;
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
		<title>Login</title>
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
              if(!empty($loginErr)){
                echo "<h2>" .$loginErr. "</h2><br/>";
              }
              if($flag == 1) {
                echo "<p>" .$emailErr . "</p>";
                echo "<p>" . $passErr . "</p>";
              }
            ?>
          </div>
          <h2>Login<h2>
          <form method="post">
            <label for="EmailAddress">Email Address</label>
            <input name="EmailAddress" type="email">
            <br/>
            <label for="Password">Password</label>
            <input name="Password" type="password" />
            <br/>
            <input type="submit" value="Login"/>
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
