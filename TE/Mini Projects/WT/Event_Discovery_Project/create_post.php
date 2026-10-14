<?php
require_once __DIR__ . '/includes/db.php';
require_once __DIR__ . '/includes/auth.php';
redirectIfNotLoggedIn();

$error = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') 
{
    $title   = trim($_POST['title'] ?? '');
    $content = trim($_POST['content'] ?? '');
    $event_date = $_POST['event_date'] ?? null;
    $location   = trim($_POST['location'] ?? '');
    $category   = trim($_POST['category'] ?? '');
    if (!$title || !$content) 
    {
        $error = 'Both title and content are required.';
    } 
    else 
    {
        $stmt = $pdo->prepare("INSERT INTO posts (user_id, title, content, event_date, location, category) VALUES (?, ?, ?, ?, ?, ?)");
        $stmt->execute([$_SESSION['user_id'], $title, $content, $event_date, $location, $category]);
        $newId = $pdo->lastInsertId();
        header("Location: /blogsite/post.php?id=$newId"); exit;
    }
}
$pageTitle = 'Write a Post';
include __DIR__ . '/includes/header.php';
?>

<div class="container">
<div class="write-card">
    <h1>Write a new post</h1>
    <p class="subtitle">Share your ideas, stories, and knowledge with the world.</p>

    <?php if ($error): ?>
        <div class="alert alert-error"><?php echo htmlspecialchars($error); ?></div>
    <?php endif; ?>

    <form method="POST">
        <div class="form-group">
            <label>Title</label>
            <input type="text" name="title"
                   value="<?php echo htmlspecialchars($_POST['title'] ?? ''); ?>"
                   placeholder="Give your post a compelling title"
                   style="font-size:20px;font-family:'Playfair Display',serif;font-weight:600;padding:14px 18px"
                   required>
        </div>
        <div class="form-group">
            <label>Content</label>
            <textarea name="content"
                      style="min-height:340px;font-size:16px;line-height:1.75"
                      placeholder="Write your story here..."
                      required><?php echo htmlspecialchars($_POST['content'] ?? ''); ?></textarea>
        </div>
        

        <div class="form-group">
            <label>Event Date</label>
            <input name="event_date" type="datetime-local"
                value="<?php echo htmlspecialchars($_POST['event_date'] ?? ''); ?>" required>
        </div>

        <div class="form-group">
            <label>Location</label>
            <input name="location" type="text"
                value="<?php echo htmlspecialchars($_POST['location'] ?? ''); ?>" required>
        </div>

        <div class="form-group">
        <label>Category</label>
        <select name="category" required>
        <option value="">Select Category</option>

        <option value="Concert" 
            <?php if (($_POST['category'] ?? '') == 'Concert') echo 'selected'; ?>>
            🎵 Concert
        </option>

        <option value="Workshop" 
            <?php if (($_POST['category'] ?? '') == 'Workshop') echo 'selected'; ?>>
            💼 Workshop
        </option>

        <option value="Meetup" 
            <?php if (($_POST['category'] ?? '') == 'Meetup') echo 'selected'; ?>>
            🤝 Meetup
        </option>

        <option value="Festival" 
            <?php if (($_POST['category'] ?? '') == 'Festival') echo 'selected'; ?>>
            🎉 Festival
        </option>

        <option value="Sports" 
            <?php if (($_POST['category'] ?? '') == 'Sports') echo 'selected'; ?>>
            🏃 Sports
        </option>

        <option value="Seminar" 
            <?php if (($_POST['category'] ?? '') == 'Seminar') echo 'selected'; ?>>
            📚 Seminar
        </option>

        <option value="Hackathon" 
            <?php if (($_POST['category'] ?? '') == 'Hackathon') echo 'selected'; ?>>
            💻 Hackathon
        </option>

        <option value="Party" 
            <?php if (($_POST['category'] ?? '') == 'Party') echo 'selected'; ?>>
            🎈 Party
        </option>

        <option value="Exhibition" 
            <?php if (($_POST['category'] ?? '') == 'Exhibition') echo 'selected'; ?>>
            🖼 Exhibition
        </option>

        <option value="Food & Drink" 
            <?php if (($_POST['category'] ?? '') == 'Food & Drink') echo 'selected'; ?>>
            🍔 Food & Drink
        </option>

        <option value="Charity" 
            <?php if (($_POST['category'] ?? '') == 'Charity') echo 'selected'; ?>>
            🙌 Charity
        </option>

        <option value="Other" 
            <?php if (($_POST['category'] ?? '') == 'Other') echo 'selected'; ?>>
            🔖 Other
        </option>

        </select>

        <br>
        <br>

        <div class="form-actions">
            <button type="submit" class="btn">Publish post</button>
            <a href="/blogsite/index.php" class="btn-outline">Cancel</a>
        </div>

        </div>
    </form>
</div>
</div>

<?php include __DIR__ . '/includes/footer.php'; ?>
