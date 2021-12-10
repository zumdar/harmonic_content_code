# DOCNADO
---

This documentation site is created with docnado. I have gone down the rabbit hole trying different static site generators found on [this website](https://github.com/myles/awesome-static-generators). I tried [gitbook](https://www.gitbook.com/), [docusaurus](https://docusaurus.io/), [mkdocs](https://www.mkdocs.org/), [doctave](https://github.com/Doctave/doctave), and [docsify](https://docsify.js.org/#/). I am not a great command line operator or an expert web developer. I know just enough to get in trouble. 
I found Docnado to be the simplist of all the options, and it reliable would work. 

Here is the basics of how I got it to work, im paraphrasing from docnado [documentation site](https://heinventions.github.io/docnado-site/example-site/w/home.html)

- you have to use the command line. I have a windows 10 machine. I use [GIT Bash](https://gitforwindows.org/) for everything needed. I think its a linux command line emulator but i really dont understand/know/care. 
- make sure you have python 3.6 or higher
	- type 'python3 --version' in CLI
- make sure you hae pip. its some kind of package manager for python. i dont really know what that is either, but if you have a fairly current version of python you should have pip. 
	- type 'python3 -m pip -V' in CLI and that should show which version of pip you have
- run this from the command line: 'python3 -m pip install docnado --upgrade'
	- if it installs you are golden. thats pretty much it because i have set up all the rest of the project.
- make sure you are working from this documentation directory. i just right click in the folder and there is an option from my menu that says 'git bash here'  type 'docnado' from CLI. this should start a server and you can access the site from something like http://127.0.0.1:5000/ on your browser.  

OK... so now change files add stuff whatever. Make sure each new .md file has its metadata at the top of the page. you can use the ones already created to copy pasta. 
I use [obsidian](https://obsidian.md/) to do the documentation. you can preview in there put images in easy and everything.  

when you are ready to actually upload a site to the web (!!!) make sure it looks good by running it in the local host (do the 'docnado' command and check how it looks)
 - now just run 'docnado -html html_files' and it will spit everything out into a html_files folder.
 - ##  !!!!!!!! one caveat!! make sure you rename 'home.html' in the 'w' folder to be 'index.html'


