<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';

if (isLoggedIn()) {
    $id = $_SESSION['user_id']; // Always logged-in user
} else {
    $id = intval($_GET['id'] ?? 0); // For public viewing
}

if (!$id) { header("Location: /blogsite/index.php"); exit; }

$stmt = $pdo->prepare("SELECT * FROM users WHERE id = ?");
$stmt->execute([$id]);
$user = $stmt->fetch();

if (!$user) {
    // Session is invalid → user deleted or DB reset
    session_destroy();
    header("Location: /blogsite/login.php");
    exit;
}

$stmt = $pdo->prepare("SELECT * FROM posts WHERE user_id = ? ORDER BY created_at DESC");
$stmt->execute([$id]);
$posts = $stmt->fetchAll();

$stmt = $pdo->prepare("SELECT COUNT(*) FROM comments WHERE user_id = ?");
$stmt->execute([$id]);
$commentCount = $stmt->fetchColumn();

$pageTitle = $user['username'] . "'s Profile";
include __DIR__ . '/includes/header.php';
?>

<div class="container">

<div class="profile-header">
    <img class="profile-avatar"
         src="/blogsite/uploads/profile_pics/<?php echo htmlspecialchars($user['profile_pic'] ?? ''); ?>"
         onerror="this.src='https://ui-avatars.com/api/?name=<?php echo urlencode($user['username']); ?>&background=c8622a&color=fff&size=88&bold=true'"
         alt="<?php echo htmlspecialchars($user['username']); ?>">

    <div class="profile-info">
        <h1><?php echo htmlspecialchars($user['username']); ?></h1>
        <p class="username"><?php echo htmlspecialchars($user['email']); ?> &nbsp;·&nbsp; Joined <?php echo date('M Y', strtotime($user['created_at'])); ?></p>
        <p class="bio"><?php echo !empty($user['bio']) ? htmlspecialchars($user['bio']) : '<em style="color:var(--ink-muted)">No bio yet.</em>'; ?></p>
        <div class="profile-stats">
            <div class="stat-item">
                <strong><?php echo count($posts); ?></strong>
                <span>Posts</span>
            </div>
            <div class="stat-item">
                <strong><?php echo $commentCount; ?></strong>
                <span>Comments</span>
            </div>
        </div>
    </div>

    <?php if (isLoggedIn() && $_SESSION['user_id'] == $id): ?>
        <div class="profile-actions">
            <a href="/blogsite/edit_profile.php" class="btn-outline">Edit profile</a>
        </div>
    <?php endif; ?>
</div>

<div class="page-header">
    <h1>Posts by <?php echo htmlspecialchars($user['username']); ?></h1>
</div>

<?php if (empty($posts)): ?>
    <div class="empty-state">
        <div class="es-icon">📝</div>
        <h3>No posts yet</h3>
        <p><?php echo isLoggedIn() && $_SESSION['user_id'] == $id ? "You haven't written anything yet." : "This user hasn't posted yet."; ?></p>
        <?php if (isLoggedIn() && $_SESSION['user_id'] == $id): ?>
            <a href="/blogsite/create_post.php" class="btn">Write your first post</a>
        <?php endif; ?>
    </div>
<?php else: ?>
    <?php foreach ($posts as $i => $post): ?>
        <div class="card" style="animation-delay:<?php echo $i * 0.05; ?>s">
            <h2><a href="/blogsite/post.php?id=<?php echo $post['id']; ?>"><?php echo htmlspecialchars($post['title']); ?></a></h2>
            <div class="meta"><?php echo date('M j, Y', strtotime($post['created_at'])); ?></div>
            <p><?php echo htmlspecialchars(substr($post['content'], 0, 180)) . '...'; ?></p>
            <div class="card-actions">
                <a href="/blogsite/post.php?id=<?php echo $post['id']; ?>" class="btn-outline">Read more</a>
                <?php if (isLoggedIn() && $_SESSION['user_id'] == $id): ?>
                    <a href="/blogsite/delete_post.php?id=<?php echo $post['id']; ?>"
                       class="btn-danger"
                       onclick="return confirm('Delete this post permanently?')">Delete</a>
                <?php endif; ?>
            </div>
        </div>
    <?php endforeach; ?>
<?php endif; ?>

</div>
<?php include __DIR__ . '/includes/footer.php'; ?>
