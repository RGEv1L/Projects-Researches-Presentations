<?php
session_start();
if($_SESSION['type']=="admin")
{
    echo"<a id='a' href='addproducts.php'>Add Products</a>";
}
?>
<!Doctype html>
<html>
<head>
	<link rel="stylesheet" href="../Css/products.css"/>
</head>
<body>
	<header class="header">
		<img  id ="headlogo" src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQHEK2M1QLvyvgymINttqGZhLAlCW4PUAwFqBlpS0-Ee60DnN4f" alt="companylogo">
	</header>
	<div id="navigation-bar">
	<div id="navigation-section">
		<div class="home-div">
			<a id="a" class="home-text" href="home1.php">Home</a>
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
	<div class="line"></div>
	</div>
	<section id="event-section">
        <div id="first-rowproduct">
            <div id=pic1-div>
                <img  src="../product-animal.jpg" alt="Animal whey">
                <P><a href="animalwhey.html">Animal Whey</a></P>
                <P>Code-101</P>
            </div>
            <div id=pic2-div>
                <img src="../product-mp.jpg" alt="Mp Combat">
                <P><a href="Mpcombat.html">Mp Combat</a></P>
                <P>Code-102</P>
            </div>
            <div id=pic3-div>
                <img src="../product-iso.jpg" alt="Dynamtize Iso">
                <P><a href="iso100.html">Dynamtize-Iso-100</a></P>
                <P>Code-103</P>
            </div>
             <div id=pic4-div>
                 <img src="../product-on.jpg" alt="ON whey">
                 <P><a href="Onwhey.html">ON Whey</a></P>
                <P>Code-104</P>
            </div>
        </div>
         <div id="second-rowproduct">
            <div id=pic1-div>
                <img  src="../product-phase8.jpg" alt="phase 8">
                <P><a href="phase8.html">Phase 8</a></P>
                <P>Code-105</P>
            </div>
            <div id=pic2-div>
                <img src="../muscle-fusion.jpg" alt="Muscle-fusion">
                <P><a href="Musclefusion.html">Muscle Fusion</a></P>
                <P>Code-106</P>
            </div>
            <div id=pic3-div>
                <img src="../syntha-6.jpeg" alt="Syntha-6">
                <p><a href="syntha-6.html">Syntha-6</a></p>
                <P>Code-107</P>
            </div>
             <div id=pic4-div>
                 <img src="../product-nitrotech.jpg" alt="Nitro Tech">
                 <P><a href="Nitrotech.html">Nitro Tech</a></P>
                <P>Code-108</P>
            </div>
        </div>
		
	</section>
</body>
</html>