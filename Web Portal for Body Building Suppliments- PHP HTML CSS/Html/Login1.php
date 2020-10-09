<?php
session_start();
$db_host="localhost";
$db_user="root";
$db_password="";
$db_name="web_db";
$error='';
$conn=mysqli_connect($db_host,$db_user,$db_password,$db_name);
if(isset($_POST['username']))
{
$username=$_REQUEST['username'];
$password=$_REQUEST['password'];
$sql="SELECT * FROM login WHERE username='$username' and password='$password'";
$result=mysqli_query($conn,$sql);
$count=mysqli_num_rows($result);
$row=mysqli_fetch_assoc($result);
if($count==1 && $row['type']=="admin")
{
    $_SESSION['login']=true;
    $_SESSION['type']=$row['type'];
    header("location:home1.php");
}
    elseif($count==1 && $row['type']=="user")
{
    $_SESSION['login']=true;
    $_SESSION['type']=$row['type'];
    header("location:home1.php");
}
else{
    $error="Your Login Name and Password is Incorrect!";
    
}
}

?>
<!Doctype html>
<html>
<head>
	<link rel="stylesheet" href="../Css/login.css"/>
    <link href="https://use.fontawesome.com/releases/v5.0.7/css/all.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/d21aa0cfaa.js" crossorigin="anonymous"></script>
    <title>LogIn-page </title>
</head>
<body>
	<header class="header">
		<img  id ="headlogo" src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQHEK2M1QLvyvgymINttqGZhLAlCW4PUAwFqBlpS0-Ee60DnN4f" alt="companylogo">
	</header>
	<div id="navigation-bar">
	<div id="navigation-section">
		<div class="home-div">
			<a class="home-text" href="home1.php">Home</a>
		</div>
		<div class="aboutus-div">
			<a class="aboutus-text" href="aboutus.php">About Us</a>
		</div>
		<div class="products-div">
			<a class="Products-text" href="products1.php">Products</a>
		</div>
		<div class="event-div">
			<a class="event-text" href="events1.php">Events</a>
		</div>
		<div class="contactus-div">
			<a class="contactus-text" href="contactus.html">Contact Us</a>
		</div>
	</div>
	<div class="line"></div>
	</div>
	<section id="event-section">
        <div class="error"><?php echo "<span style='color: red;' /><center>$error</center></span> "?></div>
        <div id="ex">
        <form action="" method="post" id="login-box" name="myform">
            <h1 >Login</h1>
            <div id="info-box">
                <i class="fas fa-user"></i>
                <input id="user-input" type="email" name="username" placeholder="Username" value="">
            </div>
            <div id="info-box2">
                <i class="fas fa-lock"></i>
                <input id="password-input" type="password" name="password"  placeholder="Password" value="">
            </div>
            <div>
                <input id="login-btn"type="submit" name="login" value="login">
            </div>
        </form>
        </div>

    </section>
    
<script>
 document.getElementById("login-btn").onclick=function()
 {
      var name = document.getElementById("user-input").value;
      var password =  document.getElementById("password-input").value;
     if(name == ""){ 
         document.getElementById("info-box").style.borderColor="red";
         document.getElementById("user-input").style.color="red";
         document.getElementById("user-input").placeholder="Enter Valid Input !";
         
     }
     if(password == ""){
         document.getElementById("info-box2").style.borderColor="red";
         document.getElementById("password-input").style.color="red";
         document.getElementById("password-input").placeholder="Enter Valid Input !";
         
     }
}
    </script>
</body>
</html>