<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';

$pageTitle = 'Home';

$stmt = $pdo->query("
    SELECT posts.*, users.username,
    COUNT(likes.id) AS like_count
    FROM posts
    LEFT JOIN likes ON posts.id = likes.post_id
    JOIN users ON posts.user_id = users.id
    GROUP BY posts.id
    ORDER BY posts.created_at DESC
");

$posts = $stmt->fetchAll();

include __DIR__ . '/includes/header.php';
?>

<div class="container">

<?php if (!isLoggedIn()): ?>
<div class="hero">
    <h1>Discover local events.</h1>
    <p>A community platform to find, share, and engage with events around you.</p>
    <a href="/blogsite/register.php" class="btn">Join now</a>
</div>
<?php endif; ?>

<div class="page-header">
    <div>
        <h1>Latest Events</h1>
        <div class="count"><?php echo count($posts); ?> events</div>
    </div>
    
    <?php if (isLoggedIn()): ?>
        <a href="/blogsite/create_post.php" class="btn">+ New Event</a>
    <?php endif; ?>
    <br>
</div>

<br>
<br>

<?php foreach ($posts as $post): ?>
    <div class="card">

        <h2>
            <a href="/blogsite/post.php?id=<?php echo $post['id']; ?>">
                <?php echo htmlspecialchars($post['title']); ?>
            </a>
        </h2>

        <div class="meta">
            By 
            <a href="/blogsite/profile.php?id=<?php echo $post['user_id']; ?>">
                <?php echo htmlspecialchars($post['username']); ?>
            </a>
            <span class="dot">·</span>
            ❤️ <span class="like-count"><?php echo $post['like_count']; ?></span> likes
        </div>

        <p>
            <?php echo htmlspecialchars(substr($post['content'], 0, 220)); ?>
            <?php echo strlen($post['content']) > 220 ? '...' : ''; ?>
        </p>

        <button class="like-btn" data-id="<?php echo $post['id']; ?>">
            ❤️ Like
        </button>

    </div>
<?php endforeach; ?>

</div>

<script>
document.querySelectorAll(".like-btn").forEach(btn => {
    btn.addEventListener("click", function () {
        let postId = this.dataset.id;
        let card = this.closest(".card");
        let countSpan = card.querySelector(".like-count");

        fetch("/blogsite/like.php", {
            method: "POST",
            headers: {"Content-Type": "application/x-www-form-urlencoded"},
            body: "post_id=" + postId
        })
        .then(res => res.json())
        .then(data => {
            if (data.likes !== undefined) {
                countSpan.innerText = data.likes;
            }
        });
    });
});
</script>

<?php include __DIR__ . '/includes/footer.php'; ?>