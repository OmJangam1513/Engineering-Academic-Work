<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';

$id = intval($_GET['id'] ?? 0);
if (!$id) { header("Location: /blogsite/index.php"); exit; }

$stmt = $pdo->prepare("
    SELECT posts.*, users.username, users.id as author_id
    FROM posts 
    JOIN users ON posts.user_id = users.id
    WHERE posts.id = ?
");
$stmt->execute([$id]);
$post = $stmt->fetch();

if (!$post) { die("Post not found."); }

// add comment
$commentError = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isLoggedIn()) {
    $body = trim($_POST['body'] ?? '');
    if ($body) {
        $stmt = $pdo->prepare("INSERT INTO comments (post_id, user_id, body) VALUES (?, ?, ?)");
        $stmt->execute([$id, $_SESSION['user_id'], $body]);
        header("Location: /blogsite/post.php?id=$id");
        exit;
    } else {
        $commentError = 'Comment cannot be empty.';
    }
}

// comments
$stmt = $pdo->prepare("
    SELECT comments.*, users.username
    FROM comments 
    JOIN users ON comments.user_id = users.id
    WHERE post_id = ? 
    ORDER BY comments.created_at ASC
");
$stmt->execute([$id]);
$comments = $stmt->fetchAll();

// like count
$stmt = $pdo->prepare("SELECT COUNT(*) FROM likes WHERE post_id = ?");
$stmt->execute([$id]);
$likeCount = $stmt->fetchColumn();

$pageTitle = $post['title'];
include __DIR__ . '/includes/header.php';
?>

<div class="container">

<div class="post-hero">

    <span class="post-badge">Event</span>

    <h1 class="post-title">
        <?php echo htmlspecialchars($post['title']); ?>
    </h1>

    <div class="post-meta">
        By 
        <a href="/blogsite/profile.php?id=<?php echo $post['author_id']; ?>">
            <?php echo htmlspecialchars($post['username']); ?>
        </a>
        <span class="dot">·</span>
        <?php echo date('F j, Y', strtotime($post['created_at'])); ?>
        <span class="dot">·</span>
        ❤️ <span id="likeCount"><?php echo $likeCount; ?></span> likes
    </div>

    <?php if (isLoggedIn()): ?>
        <button class="like-btn" data-id="<?php echo $id; ?>">
            ❤️ Like / Unlike
        </button>
    <?php endif; ?>

    <div class="post-body">
        <?php echo nl2br(htmlspecialchars($post['content'])); ?>
    </div>

</div>

<div class="comments-wrap">

    <h3 class="comments-title">
        Comments <span class="comments-count"><?php echo count($comments); ?></span>
    </h3>

    <?php foreach ($comments as $c): ?>
        <div class="comment">
            <div class="comment-header">
                <a href="/blogsite/profile.php?id=<?php echo $c['user_id']; ?>" class="comment-avatar">
                    <?php echo strtoupper(substr($c['username'], 0, 1)); ?>
                </a>

                <div class="comment-meta-info">
                    <a class="author"><?php echo htmlspecialchars($c['username']); ?></a>
                    <span class="time">
                        <?php echo date('M j, Y g:i a', strtotime($c['created_at'])); ?>
                    </span>
                </div>
            </div>

            <div class="comment-body">
                <?php echo nl2br(htmlspecialchars($c['body'])); ?>
            </div>
        </div>
    <?php endforeach; ?>

    <?php if (isLoggedIn()): ?>
        <form method="POST" class="comment-form">
            <textarea name="body" placeholder="Write a comment..."></textarea>
            <button type="submit" class="btn">Post Comment</button>
        </form>
    <?php else: ?>
        <p><a href="/blogsite/login.php">Login</a> to comment.</p>
    <?php endif; ?>

</div>

</div>

<script>
document.querySelector(".like-btn")?.addEventListener("click", function () {
    let postId = this.dataset.id;

    fetch("/blogsite/like.php", {
        method: "POST",
        headers: {"Content-Type": "application/x-www-form-urlencoded"},
        body: "post_id=" + postId
    })
    .then(res => res.json())
    .then(data => {
        if (data.likes !== undefined) {
            document.getElementById("likeCount").innerText = data.likes;
        }
    });
});
</script>

<?php include __DIR__ . '/includes/footer.php'; ?>