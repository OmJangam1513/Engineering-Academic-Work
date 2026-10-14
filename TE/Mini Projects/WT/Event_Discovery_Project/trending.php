<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';

$pageTitle = "Trending Events";

$stmt = $pdo->query("
    SELECT posts.*, users.username,
    COUNT(likes.id) AS like_count
    FROM posts
    LEFT JOIN likes ON posts.id = likes.post_id
    JOIN users ON posts.user_id = users.id
    GROUP BY posts.id
    ORDER BY like_count DESC, posts.created_at DESC
");

$posts = $stmt->fetchAll();

include __DIR__ . '/includes/header.php';
?>

<div class="container">

<div class="page-header">
    <div>
        <h1>🔥 Trending Events</h1>
        <div class="count"><?php echo count($posts); ?> events</div>
    </div>
</div>

<?php foreach ($posts as $post): ?>
    <div class="card">

        <h2>
            <a href="/blogsite/post.php?id=<?php echo $post['id']; ?>">
                <?php echo htmlspecialchars($post['title']); ?>
            </a>
        </h2>

        <div class="meta">
            By <?php echo htmlspecialchars($post['username']); ?>
            <span class="dot">·</span>
            ❤️ <?php echo $post['like_count']; ?> likes
        </div>

        <p>
            <?php echo htmlspecialchars(substr($post['content'], 0, 200)); ?>...
        </p>

    </div>
<?php endforeach; ?>

</div>

<?php include __DIR__ . '/includes/footer.php'; ?>