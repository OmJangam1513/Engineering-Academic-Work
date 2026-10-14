<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';
redirectIfNotLoggedIn();

$stmt = $pdo->prepare("SELECT * FROM users WHERE id = ?");
$stmt->execute([$_SESSION['user_id']]);
$user = $stmt->fetch();

$success = '';
$error   = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $bio      = trim($_POST['bio'] ?? '');
    $email    = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    $pic      = $user['profile_pic'];

    if (!empty($_FILES['profile_pic']['name'])) {
        $allowed = ['image/jpeg', 'image/png', 'image/gif', 'image/webp'];
        $mime    = mime_content_type($_FILES['profile_pic']['tmp_name']);
        if (!in_array($mime, $allowed)) {
            $error = 'Only JPG, PNG, GIF, or WEBP images are allowed.';
        } elseif ($_FILES['profile_pic']['size'] > 2 * 1024 * 1024) {
            $error = 'Image must be under 2MB.';
        } else {
            $ext = pathinfo($_FILES['profile_pic']['name'], PATHINFO_EXTENSION);
            $pic = 'user_' . $_SESSION['user_id'] . '_' . time() . '.' . $ext;
            move_uploaded_file($_FILES['profile_pic']['tmp_name'], __DIR__ . '/uploads/profile_pics/' . $pic);
        }
    }

    if (!$error) {
        if ($password) {
            $hash = password_hash($password, PASSWORD_DEFAULT);
            $stmt = $pdo->prepare("UPDATE users SET bio=?, email=?, password_hash=?, profile_pic=? WHERE id=?");
            $stmt->execute([$bio, $email, $hash, $pic, $_SESSION['user_id']]);
        } else {
            $stmt = $pdo->prepare("UPDATE users SET bio=?, email=?, profile_pic=? WHERE id=?");
            $stmt->execute([$bio, $email, $pic, $_SESSION['user_id']]);
        }
        $success = 'Profile updated successfully!';
        $stmt = $pdo->prepare("SELECT * FROM users WHERE id = ?");
        $stmt->execute([$_SESSION['user_id']]);
        $user = $stmt->fetch();
    }
}
$pageTitle = 'Edit Profile';
include __DIR__ . '/includes/header.php';
?>

<div class="container">
<div class="edit-card">
    <h1>Edit profile</h1>
    <p class="subtitle">Update your personal information and profile picture.</p>

    <?php if ($success): ?><div class="alert alert-success"><?php echo $success; ?></div><?php endif; ?>
    <?php if ($error):   ?><div class="alert alert-error"><?php echo htmlspecialchars($error); ?></div><?php endif; ?>

    <form method="POST" enctype="multipart/form-data">

        <div class="avatar-upload">
            <img src="/blogsite/uploads/profile_pics/<?php echo htmlspecialchars($user['profile_pic'] ?? ''); ?>"
                 onerror="this.src='https://ui-avatars.com/api/?name=<?php echo urlencode($user['username']); ?>&background=c8622a&color=fff&size=68&bold=true'"
                 alt="Profile photo" id="avatarPreview">
            <div class="avatar-info">
                <strong>Profile photo</strong>
                <small>JPG, PNG, GIF or WEBP · Max 2MB</small>
                <br>
                <label class="btn-outline" style="margin-top:8px;font-size:13px;padding:6px 14px;cursor:pointer">
                    Choose photo
                    <input type="file" name="profile_pic" accept="image/*" style="display:none"
                           onchange="previewAvatar(this)">
                </label>
            </div>
        </div>

        <span class="section-title">Account info</span>

        <div class="form-group">
            <label>Email</label>
            <input type="email" name="email" value="<?php echo htmlspecialchars($user['email']); ?>" required>
        </div>
        <div class="form-group">
            <label>Bio</label>
            <textarea name="bio" placeholder="Tell readers about yourself..."><?php echo htmlspecialchars($user['bio'] ?? ''); ?></textarea>
        </div>

        <span class="section-title">Change password</span>

        <div class="form-group">
            <label>New password <span style="font-weight:400;text-transform:none;letter-spacing:0;color:var(--ink-muted)">(leave blank to keep current)</span></label>
            <input type="password" name="password" placeholder="Enter new password">
        </div>

        <div class="form-actions">
            <button type="submit" class="btn">Save changes</button>
            <a href="/blogsite/profile.php?id=<?php echo $_SESSION['user_id']; ?>" class="btn-outline">Cancel</a>
        </div>
    </form>
</div>
</div>

<script>
function previewAvatar(input) {
    if (input.files && input.files[0]) {
        const reader = new FileReader();
        reader.onload = e => document.getElementById('avatarPreview').src = e.target.result;
        reader.readAsDataURL(input.files[0]);
    }
}
</script>

<?php include __DIR__ . '/includes/footer.php'; ?>
