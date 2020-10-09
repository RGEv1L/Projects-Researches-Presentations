<?php
session_start();
$db_host="localhost";
$db_user="root";
$db_password="";
$db_name="web_db";
$error='';
if(isset($_REQUEST['addproduct']))
{
$product_name=$_POST['productname'];
$product_code=$_POST['productcode'];
$conn=mysqli_connect($db_host,$db_user,$db_password,$db_name);
$sql="INSERT INTO products(code,name)VALUES('$product_code','$product_name')";
    if(mysqli_query($conn,$sql))
{
    header("location:showproducts.php");
}
else{
    echo"Not Inserted";
}
}

?>
<!Doctype html>
<html>
<head>
	<link rel="stylesheet" href="../Css/addproducts.css"/>
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
        <div id="ex">
        <form action="" method="post" id="login-box" name="myform">
            <h1 >Add Products</h1>
            <div id="info-box">
                <input id="user-input" type="text" name="productname" placeholder="Product Name" value="">
            </div>
            <div id="info-box2">
                <input id="password-input" type="text" name="productcode"  placeholder="Product Code" value="">
            </div>
            <div>
                <input id="login-btn"type="submit" name="addproduct" value="Add Product">
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