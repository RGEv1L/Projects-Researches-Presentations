<?php
session_start();
$db_host="localhost";
$db_user="root";
$db_password="";
$db_name="web_db";
$error='';
$conn=mysqli_connect($db_host,$db_user,$db_password,$db_name);
if(isset($_REQUEST['delete']))
{   $id=$_REQUEST['id'];
 echo $id;
    $del="DELETE FROM products WHERE  id = $id";
    if(mysqli_query($conn,$del))
    {
        echo"row deleted";
    }
}
elseif(isset($_REQUEST['edit'])){
    $id=$_REQUEST['id'];
    if(isset($id)){
        $_SESSION['update']=true;
        $_SESSION['id']=$id;
        header("location:addproducts.php");
    }
    
}
$sql="SELECT * FROM products";
$result=mysqli_query($conn,$sql);
$count=mysqli_num_rows($result);
?>
<html>
<head>
	<link rel="stylesheet" href="../Css/showproducts.css"/>
</head>
<body>
	<header class="header">
		<img  id ="headlogo" src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQHEK2M1QLvyvgymINttqGZhLAlCW4PUAwFqBlpS0-Ee60DnN4f" alt="companylogo">
	</header>
	<div id="navigation-bar">
	<div id="navigation-section">
		<div class="home-div">
			<a id="a"class="home-text" href="home1.php">Home</a>
		</div>
		<div class="aboutus-div">
			<a id="a" class="aboutus-text" href="aboutus.php">About Us</a>
		</div>
		<div class="products-div">
			<a id="a" class="Products-text" href="products1.php">Products</a>
		</div>
		<div class="event-div">
			<a id="a" class="event-text" href="events1.php">Events</a>
		</div>
		<div class="contactus-div">
			<a id="a" class="contactus-text" href="contactus.html">Contact Us</a>
		</div>
	</div>
	</div>
    <section class="table-section">
        <div id="table-div">
        
                <?php
            if($count>0)
            {
                echo"<table class='table' id='table'>";
            echo"<thead>";
                echo"<tr>";
                    echo"<th>Sr No</th>";
                    echo"<th>Code</th>";
                    echo"<th>Name</th>";
                    echo"<th>Action</th>";
                echo"</tr>";
            echo"</thead>";
            echo"<tbody>";
            
                while($row=mysqli_fetch_assoc($result))
                { 
                    
                    echo"<tr>";
                    echo"<td>".$row['id']."</td>";
                    echo"<td>".$row['code']."</td>";
                    echo"<td>".$row['name']."</td>";
                    echo'<td><form action="" method="post"><input type="hidden" name="id" value=' . $row['id'] .'><input class="form-btn" type="submit" name="edit" value="Edit"/><input class="form-btn" type="submit" name="delete" value="Delete"/></form></td>';
                echo"</tr>";  
                }
                   echo"</tbody>";
            echo"</table>";
            }    ?>
        </div>
        
    </section>
	
</body>
</html>