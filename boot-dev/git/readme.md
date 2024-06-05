# Porcelain and Plumbing

In Git, commands are divided into high-level ("porcelain") commands and low-level ("plumbing") commands. The porcelain commands are the ones that you will use most often as a developer to interact with your code. Some porcelain commands are:

    git status
    git add
    git commit
    git push
    git pull
    git log

Don't worry about what they do yet, we'll cover them in detail soon. Some examples of plumbing commands are:

    git apply
    git commit-tree
    git hash-object

We'll focus on the high-level commands because that's what you use 99% of the time as a developer, but we'll dip down into the low-level commands occasionally to really understand how Git works.

# Cat File

Luckily, Git has a built-in plumbing command, cat-file, that allows us to see the contents of a commit without needing to futz around with the object files directly.

git cat-file -p <hash>

Assignment

Use the cat-file command to view the contents of your last commit.
Pass an argument to the CLI

Notice that the bootdev CLI "run" and "submit" for this lesson take an additional argument denoted by a $1:

git cat-file -p $1

You need to provide the hash of your last commit so that the CLI can run the command for you.

Run and submit the tests. Provide the same hash you used in the cat-file command as an argument.

# Trees and Blobs

Now that we understand some of our plumbing equipment, let's get into the pipes. Here are some terms to know:

    tree: git's way of storing a directory
    blob: git's way of storing a file

Here's what I got when I inspected my last commit:

> git cat-file -p 5ba786fcc93e8092831c01e71444b9baa2228a4f

tree 4e507fdc6d9044ccd8a4a3061324c9f711c4667d
author ThePrimeagen <the.primeagen@gmail.com> 1705891256 -0700
committer ThePrimeagen <the.primeagen@gmail.com> 1705891256 -0700

A: add contents.md

Notice that we can see:

    The tree object
    The author
    The committer
    The commit message

However, we cannot see the contents of the contents.md file itself! That's because the tree object stores it.
Assignment

    Use git cat-file -p again, but this time with the hash of the tree object instead of the commit hash.
    You should see a blob object with its own hash.
    Use cat-file again to view the contents of the blob object.
    Run and submit the CLI tests, providing the same blob hash.

bootdev submit id <hash>

# Git Config

Git stores author information so that when you're making a commit it can track who made the change. Here's how you might update your global Git configuration (don't do this yet):

git config --add --global user.name "ThePrimeagen"
git config --add --global user.email "the.primeagen@aol.com"

Let's take the command apart:

    git config: The command to interact with your Git configuration.
    --add: Flag stating you want to add a configuration.
    --global: Flag stating you want this configuration to be stored globally in your ~/.gitconfig. The opposite is "local", which stores the configuration in the current repository only.
    user.name: The configuration key you want to set.
    "ThePrimeagen": The value you want to set for the key.

Assignment

You can actually store any old data in your Git configuration. Granted, only certain keys are used by Git, but you can store whatever you want.

Set the following useless key/value pairs in your local Git configuration for the Webflyx repository (omit the --global flag to set them locally):

    webflyx.ceo: "ThePrimeagen"
    webflyx.cto: "TheLaneagen"
    webflyx.valuation: "mid"

Git has a command to view the contents of your config:

git config --list --local

You can also just view the contents of your local config file directly:

cat .git/config

Run and submit the tests.

## Get

We've used --list to see all the configuration values, but the --get flag is useful for getting a single value.

git config --get <key>

Keys are in the format <section>.<keyname>. For example:

    user.name
    webflyx.ceo

## Unset

The --unset flag is used to remove a configuration value. For example:

git config --unset <key>

## Duplicates

Typically, in a key/value store, like a Python dictionary, you aren't allowed to have duplicate keys. Strangely enough, Git doesn't care.
Unset All

The --unset-all flag is useful if you ever really want to purge all instances of a key from your configuration. Conversely, the --unset flag only works with a single instance of a key.

git config --unset-all example.key

## Remove a section

As I pointed out before, the webflyx section is nonsensical because Git doesn't use it for anything. While we can store any key/value pairs we want in our Git configuration, it doesn't mean we should.

The --remove-section flag is used to remove an entire section from your Git configuration. For example:

git config --remove-section section

## Locations

There are several locations where Git can be configured. From more general to more specific, they are:

    system: /etc/gitconfig, a file that configures Git for all users on the system
    global: ~/.gitconfig, a file that configures Git for all projects of a user
    local: .git/config, a file that configures Git for a specific project
    worktree: .git/config.worktree, a file that configures Git for part of a project

In my experience, 90% of the time you will be using --global to set things like your username and email. The other 9% of the time you will be using --local to set project-specific configurations. The last 1% of the time you might need to futz with system and worktree configurations, but it's extremely rare.

## Overriding

If you set a configuration in a more specific location, it will override the same configuration in a more general location. For example, if you set user.name in the local configuration, it will override the user.name set in the global configuration.

# Branch
A branch is just a named pointer to a specific commit. When you create a branch, you are creating a new pointer to a specific commit. The commit that the branch points to is called the tip of the branch.
Because a branch is just a pointer to a commit, they're lightweight and "cheap" resource-wise to create. When you create 10 branches, you're not creating 10 copies of your project on your hard drive.

# Log Flags

As you know, git log shows you the history of commits in your repo. There are a few flags I like to use from time to time to make the output easier to read.

The first is --decorate. It can be one of:

    short (the default)
    full (shows the full ref name)
    no (no decoration)

Run git log --decorate=full. You should see that instead of just using your branch name, it will show the full ref name. A ref is just a pointer to a commit. All branches are refs, but not all refs are branches.

Run git log --decorate=no. You should see that the branch names are no longer shown at all.

The second is --oneline. This flag will show you a more compact view of the log. I use this one all the time, it just makes it so much easier to see what's going on.

git log --oneline

# Reset

The git reset command can be used to reset any changes in the index (staged but not committed changes) and the worktree (unstaged and not committed changes).

git reset --hard

This is useful if you just want to discard all your current changes and go back to the last commit.

I want to stress how dangerous this command can be. When you deleted the file, because it was tracked in Git, it was trivially easy to recover. However, if you have some changes that you do want to keep, running git reset --hard will delete them for good.

Always be careful when using git reset --hard. It's a powerful tool, but it's also a dangerous one.
Reset to a Specific Commit

If you want to reset back to a specific commit, you can use the git reset --hard command and provide a commit hash. For example:

git reset --hard a1b2c3d

This will reset your working directory and index to the state of that commit, and all the changes made after that commit are lost forever.


