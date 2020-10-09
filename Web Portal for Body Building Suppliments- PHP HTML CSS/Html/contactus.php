<?php
session_start();
$error='';
if(!isset($_SESSION['login']))
{
    header("location:Login1.php");
}
elseif(isset($_SESSION['login']))
{
if($_SESSION['type']=="admin")
{
    $_SESSION['type']="admin";
}
}
if(isset($_REQUEST['sendmail']))
{
$db_host="localhost";
$db_user="root";
$db_password="";
$db_name="web_db";
$error='';
$conn=mysqli_connect($db_host,$db_user,$db_password,$db_name);
$username=$_REQUEST['username'];
$email=$_REQUEST['email'];
$message=$_REQUEST['message'];
$sql="INSERT INTO contact(username,email,message)VALUES('$username','$email','$message')";
     if(mysqli_query($conn,$sql))
{
    $error="Mail Send";
}
}
?>
<!Doctype html>
<html>
<head>
	<link rel="stylesheet" href="../Css/contactus.css"/>
    <link href="https://use.fontawesome.com/releases/v5.0.7/css/all.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/d21aa0cfaa.js" crossorigin="anonymous"></script>
    <title>Contactus</title>
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
        <div class="error"><?php echo "<h2 style='color: red;' /><center>$error</center></h2> "?></div>
        <div id="ex">
        <form id="contact-box">
            <h1 >Contact Us</h1>
            <div id="info-box">
                <i class="fas fa-user"></i>
                <input id="user-input" type="Username" name="username" placeholder="Username" value="">
            </div>
            <div id="info-box2">
                <i class="fas fa-email"></i>
                <input id="email-input" type="email" name="email"  placeholder="example@gmail.com" value="">
            </div>
            <div id="text-area">
                <textarea id="message" rows="7" cols="35" placeholder="Message"  name="message"></textarea>
            </div>
            <div>
                <input id="send-btn" type="submit" name="sendmail" value="Send Email">
            </div>
        </form>
        </div>
    </section>
        <script>
 document.getElementById("send-btn").onclick=function()
 {
      var name = document.getElementById("user-input").value;
      var email =  document.getElementById("email-input").value;
     var text_area =document.getElementById("text-area").value;
     if(name == ""){ 
         document.getElementById("info-box").style.borderColor="red";
         document.getElementById("user-input").style.color="red";
         document.getElementById("user-input").placeholder="Enter Valid Name !";
         
     }
     if(email == ""){
         document.getElementById("info-box2").style.borderColor="red";
         document.getElementById("email-input").style.color="red";
         document.getElementById("email-input").placeholder="Enter Valid Email !";
         
     }
}
 console.log("Moazzan End");
    </script>
</body>
</html>