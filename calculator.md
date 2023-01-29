<html  >

<head>

<meta charset="UTF-8">

<meta name="description" content="">




  <title>Login</title>
  <link rel="stylesheet" href="assets/tether/tether.min.css">
  <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
  <link rel="stylesheet" href="assets/bootstrap/css/bootstrap-grid.min.css">
  <link rel="stylesheet" href="assets/bootstrap/css/bootstrap-reboot.min.css">
  <link rel="stylesheet" href="assets/dropdown/css/style.css">
  <link rel="stylesheet" href="assets/socicon/css/styles.css">
  <link rel="stylesheet" href="assets/theme/css/style.css">





</head>
<body>
<section class="my-5">
    <div class="py-3">
     <h2 class="text-center"><strong>LOGIN</strong></h2>
 </div>
 <div class="w-50 m-auto">
 <div>
   <form action="logininfo.php" method="POST">
     <div class="form-group">
       <label><h3>username/email</h3></label>
       <input type="email" name="email" placeholder="username/email" data-form-field="email" class="form-control" value="" id="email"> 
     </div>
     <div class="form-group">
       <label><h3>Password</h3></label>
       <input type="password" name="password" placeholder="password" data-form-field="password" class="form-control" value="" id="password"> 
     </div>
     <div class="col-auto mbr-section-btn align-center"><button type="submit" name="submit" class="btn btn-primary btn-block">LogIn Now</button></div>
        <p class="text-center"><h3>Have not created account?<a href="signup.php">Sign Up</a></h3></p>
   </form>

</div>
</section>
</body>
</html>
