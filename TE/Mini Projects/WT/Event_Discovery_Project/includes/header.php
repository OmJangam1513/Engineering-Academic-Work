<?php require_once __DIR__ . '/auth.php'; ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>
        <?php echo isset($pageTitle) ? htmlspecialchars($pageTitle) . ' | EventDiscoverY' : 'EventDiscoverY'; ?>
    </title>

    <!-- ✅ FIX: RELATIVE PATH (this is the correct fix for CSS not loading) -->
    <link rel="stylesheet" href="assets/css/style.css">
</head>

<body>

<nav class="navbar">
    <!-- ✅ FIX: RELATIVE LINKS (no /blogsite prefix) -->

    <a href="index.php" class="brand">EventDiscoverY</a>

    <div class="nav-links">
        <?php if (isLoggedIn()): ?>
            <a href="index.php">Home</a>
            <a href="trending.php">Trending</a>
            <a href="create_post.php">+ New Event</a>
            <a href="profile.php?id=<?php echo $_SESSION['user_id']; ?>">Profile</a>
            <a href="logout.php">Logout</a>
        <?php else: ?>
            <a href="login.php">Login</a>
            <a href="register.php">Register</a>
        <?php endif; ?>
    </div>
</nav>

<main class="container">