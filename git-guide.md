# Essential Git Guide for Software Engineers and Open Source Contributors

## Table of Contents
1. [Getting Started](#getting-started)
2. [Basic Commands](#basic-commands)
3. [Branching and Merging](#branching-and-merging)
4. [Remote Repositories](#remote-repositories)
5. [Advanced Commands](#advanced-commands)
6. [Best Practices](#best-practices)
7. [Common Scenarios](#common-scenarios)

## Getting Started

### Installation
```bash
# Linux (Debian/Ubuntu)
sudo apt-get update
sudo apt-get install git

# macOS (using Homebrew)
brew install git

# Windows
# Download from https://git-scm.com/download/win
```

### Initial Configuration
```bash
# Set your username
git config --global user.name "Your Name"

# Set your email
git config --global user.email "your.email@example.com"

# Set default branch name
git config --global init.defaultBranch main
```

## Basic Commands

### Initializing a Repository
```bash
# Create a new git repository
git init

# Clone an existing repository
git clone https://github.com/username/repository.git
```

### Daily Workflow Commands
```bash
# Check status of your repository
git status

# Add files to staging area
git add filename        # Add specific file
git add .               # Add all files

# Commit changes
git commit -m "Your descriptive commit message"

# View commit history
git log                 # Detailed log
git log --oneline      # Condensed log
```

## Branching and Merging

### Branch Management
```bash
# List all branches
git branch

# Create a new branch
git branch branch-name

# Switch to a branch
git checkout branch-name

# Create and switch to a new branch
git checkout -b new-branch-name

# Delete a branch
git branch -d branch-name
```

### Merging
```bash
# Merge a branch into current branch
git merge branch-name

# Abort a merge in case of conflicts
git merge --abort
```

## Remote Repositories

### Managing Remotes
```bash
# List remote repositories
git remote -v

# Add a remote repository
git remote add origin https://github.com/username/repo.git

# Remove a remote
git remote remove origin
```

### Syncing with Remote
```bash
# Download changes from remote
git fetch origin

# Download and merge changes
git pull origin main

# Upload local changes to remote
git push origin main

# Set upstream branch
git push -u origin main
```

## Advanced Commands

### Stashing Changes
```bash
# Temporarily store changes
git stash

# List stashed changes
git stash list

# Apply most recent stash
git stash pop

# Apply specific stash
git stash apply stash@{n}
```

### Reverting Changes
```bash
# Undo last commit but keep changes
git reset HEAD~1

# Completely undo last commit
git reset --hard HEAD~1

# Revert a specific commit
git revert commit-hash
```

### Interactive Rebase
```bash
# Start interactive rebase
git rebase -i HEAD~n  # n is the number of commits to go back
```

## Best Practices

1. **Commit Messages**
   - Use present tense ("Add feature" not "Added feature")
   - Be descriptive but concise
   - Reference issue numbers when applicable

2. **Branching Strategy**
   ```bash
   # Feature branch workflow
   git checkout -b feature/feature-name
   # Bug fix branch
   git checkout -b fix/bug-description
   ```

3. **Before Pushing**
   ```bash
   # Update your local main
   git checkout main
   git pull origin main
   
   # Rebase your feature branch
   git checkout feature/feature-name
   git rebase main
   ```

## Common Scenarios

### Contributing to Open Source
```bash
# Fork the repository on GitHub

# Clone your fork
git clone https://github.com/your-username/project.git

# Add original repository as upstream
git remote add upstream https://github.com/original-owner/project.git

# Create a feature branch
git checkout -b feature/amazing-feature

# Keep your fork updated
git fetch upstream
git checkout main
git merge upstream/main
```

### Resolving Merge Conflicts
```bash
# When a merge conflict occurs
1. Open the conflicted files
2. Look for conflict markers (<<<<<<<, =======, >>>>>>>)
3. Resolve the conflicts manually
4. Add the resolved files
git add .
5. Complete the merge
git commit -m "Resolve merge conflicts"
```

### Creating a Pull Request
1. Push your feature branch to your fork
```bash
git push origin feature/amazing-feature
```
2. Go to the original repository on GitHub
3. Click "New Pull Request"
4. Select your feature branch
5. Add a descriptive title and detailed description
6. Reference any related issues

## Git Aliases for Productivity
Add these to your `~/.gitconfig`:
```
[alias]
    st = status
    co = checkout
    br = branch
    ci = commit
    unstage = reset HEAD --
    last = log -1 HEAD
    visual = !gitk
```

## Tips for Success
1. **Regular Commits**: Make small, focused commits
2. **Pull Before Push**: Always pull before pushing
3. **Branch Naming**: Use descriptive, standardized branch names
4. **Code Review**: Request reviews before merging
5. **Documentation**: Update documentation with code changes

---

Remember, Git is powerful but can be complex. Start with the basics and gradually incorporate more advanced commands as you become comfortable. Always be careful with commands that rewrite history (`rebase`, `reset --hard`) on shared branches.

For more detailed information, visit:
- [Git Documentation](https://git-scm.com/doc)
- [GitHub Guides](https://guides.github.com/)
