## Linux Commands
- **ls**
  - "list"
  - Displays files and subdirectories in the directory
- **ls -a**
  - Displays hidden files and subdirectories as well
- **pwd**
  - "print working directory"
  - Displays the current directory
- **cd**
  - Changes to another directory
- **cp blabla.pdf blablabCOPY.pdf**
  - Copies the file blabla.pdf and names the copy blablabCOPY.pdf
- **mv bla.pdf /MoveHere/**
  - Moves bla.pdf to the MoveHere directory
- **mkdir NewFolder**
  - "make directory"
  - Creates a new directory named NewFolder
- **nano README.md**
  - Creates a Markdown file **Readme**
- **cd ..**
  - Changes directory to the parent directory

## Creating SSH Key Once
- **ssh-keygen -t rsa**
  - generating the key
- **Never** upload the file or content of the id_rsa without the file extension
- In the /.ssh directory   
→ **cat id rsa.pub | clip**  
Copies the contents of the file "id_rsa.pub" to the clipboard.

## Configuration Git Account
- **git config --global user.name "Max Musermann"**
- **git config --global user.email "m_mustermann@hs-ulm.de"**
- Git creates a file named .gitconfig in the home directory.

## GIT 
### Clone repository
- **cd** to working directory
- **git clone** "Content of **Clone with SSH**"
### Working with GIT
- Save the files
- check status with **git status**
- **git add .**  
  adds all the changes in the current directory and its subdirectories to the staging area for the next commit
- **git commit -m 'messageX'**  
  creates a commit with the message **messageX**
- **git push**  
  uploads local changes to a remote repository
