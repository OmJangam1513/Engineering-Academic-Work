<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';
if (isLoggedIn())
{ 
    header("Location: /blogsite/index.php"); 
    exit; 
}

$error = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $email    = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    if (!$email || !$password) {
        $error = 'Please enter your email and password.';
    } else {
        $stmt = $pdo->prepare("SELECT * FROM users WHERE email = ?");
        $stmt->execute([$email]);
        $user = $stmt->fetch();
        if ($user && password_verify($password, $user['password_hash'])) {
            $_SESSION['user_id']  = $user['id'];
            $_SESSION['username'] = $user['username'];
            header("Location: /blogsite/index.php"); exit;
        } else {
            $error = 'Invalid email or password.';
        }
    }
}
$pageTitle = 'Login';
include __DIR__ . '/includes/header.php';
?>

<div class="form-wrap">
<div class="form-card">
    <div class="form-logo">Events</div>
    <h1>Welcome back</h1>
    <p class="subtitle">Sign in to continue writing and reading.</p>

    <?php if ($error): ?>
        <div class="alert alert-error"><?php echo htmlspecialchars($error); ?></div>
    <?php endif; ?>

    <form method="POST">
        <div class="form-group">
            <label>Email</label>
            <input type="email" name="email" value="<?php echo htmlspecialchars($_POST['email'] ?? ''); ?>" placeholder="you@example.com" required>
        </div>
        <div class="form-group">
            <label>Password</label>
            <input type="password" name="password" placeholder="Your password" required>
        </div>
        <button type="submit" class="btn">Sign in</button>
    </form>
    <p class="alt-link">Don't have an account? <a href="/blogsite/register.php">Create one</a></p>
</div>
</div>

<?php include __DIR__ . '/includes/footer.php'; ?>
