<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';
if (isLoggedIn()) { header("Location: /blogsite/index.php"); exit; }

$error = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username'] ?? '');
    $email    = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    $bio      = trim($_POST['bio'] ?? '');

    if (!$username || !$email || !$password) {
        $error = 'Please fill in all required fields.';
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $error = 'Please enter a valid email address.';
    } elseif (strlen($password) < 6) {
        $error = 'Password must be at least 6 characters.';
    } else {
        $stmt = $pdo->prepare("SELECT id FROM users WHERE username = ? OR email = ?");
        $stmt->execute([$username, $email]);
        if ($stmt->fetch()) {
            $error = 'Username or email is already taken.';
        } else {
            $hash = password_hash($password, PASSWORD_DEFAULT);
            $stmt = $pdo->prepare("INSERT INTO users (username, email, password_hash, bio) VALUES (?, ?, ?, ?)");
            $stmt->execute([$username, $email, $hash, $bio]);
            $_SESSION['user_id']  = $pdo->lastInsertId();
            $_SESSION['username'] = $username;
            header("Location: /blogsite/index.php"); exit;
        }
    }
}
$pageTitle = 'Create account';
include __DIR__ . '/includes/header.php';
?>

<div class="form-wrap">
<div class="form-card" style="max-width:500px">
    <div class="form-logo">BlogSite</div>
    <h1>Create your account</h1>
    <p class="subtitle">Join the community and start sharing your stories.</p>

    <?php if ($error): ?>
        <div class="alert alert-error"><?php echo htmlspecialchars($error); ?></div>
    <?php endif; ?>

    <form method="POST">
        <div class="form-group">
            <label>Username</label>
            <input type="text" name="username" value="<?php echo htmlspecialchars($_POST['username'] ?? ''); ?>" placeholder="yourname" required>
        </div>
        <div class="form-group">
            <label>Email</label>
            <input type="email" name="email" value="<?php echo htmlspecialchars($_POST['email'] ?? ''); ?>" placeholder="you@example.com" required>
        </div>
        <div class="form-group">
            <label>Password <span style="font-weight:400;text-transform:none;letter-spacing:0;color:var(--ink-muted)">(min 6 characters)</span></label>
            <input type="password" name="password" placeholder="Choose a strong password" required>
        </div>
        <div class="form-group">
            <label>Bio <span style="font-weight:400;text-transform:none;letter-spacing:0;color:var(--ink-muted)">(optional)</span></label>
            <textarea name="bio" placeholder="Tell us a little about yourself..."><?php echo htmlspecialchars($_POST['bio'] ?? ''); ?></textarea>
        </div>
        <button type="submit" class="btn">Create account</button>
    </form>
    <p class="alt-link">Already have an account? <a href="/blogsite/login.php">Sign in</a></p>
</div>
</div>

<?php include __DIR__ . '/includes/footer.php'; ?>
