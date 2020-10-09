<?php
session_start();
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
?>
<!Doctype html>
<html>
<head>
	<link rel="stylesheet" href="../Css/home.css"/>
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
		<h1>Latest Events</h1>
        <div class="heading-line"></div>
		<div id="event1-div">
			<div class="image-div">
				<img id="event-image" src="../Images/event-image1.jpg" >
			</div>
			<div id="event-text-div">
				<p>Being one of the biggest fitness expos in Dubai, it was an honor to have it come to ‘Pakistan’. But for us at Jacked Nutrition, perhaps the biggest achievement was to bring one of the world’s biggest bodybuilding stars to our gym in Islamabad, Pakistan.</p>
			</div>
		</div>
		<div id="event2-div">
			<div class="image-div">
				<img id="event-image" src="../Images/event-image2.jpg" >
			</div>
			<div id="event-text-div">
				<p>Team Nutrition is one of official supplier of Whey Protein, Fat Burners, Pre-Workouts and Post Workouts and many more, in Pakistan,Team Nutrition deals all official Brands of supplements in PAKISTAN only. All the products that you can find on our virtual shelves are imported from around the globe, Dubai (Primary Location) or United States (Secondary Location). Team Nutrition deals only Branded and authorized, supplements companies who have authorized us to distribute and retail supplements and other fitness accessories.Team Nutrition has in total of 10 supplements companies who have authorized us to Distribute and Retail supplements.</p>
				
			</div>
		</div>
	</section>
</body>
</html>