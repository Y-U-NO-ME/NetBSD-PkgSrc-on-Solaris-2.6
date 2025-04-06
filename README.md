# NetBSD-PkgSrc-on-Solaris-2.6
NetBSD PkgSrc on Solaris 2.6

If like me you have some older Sun or machines from the 90s that are running Solaris 2.6 but want to use a package manager type tool, then NetBSD's pkgsrc might be the right tool for you. Here's my notes and some of the files that I had to scrounge to find in order to bootstrap **pkgsrc**.
https://www.netbsd.org/docs/pkgsrc/platforms.html#bootstrapping-pkgsrc
https://ludd.ltu.se/~ragge/htdocs/Documentation/pkgsrc/platforms.html

Background
I have been getting some of my vintage servers and workstations back up and running. I have 2 machines that will not support running NetBSD or other Opensource distros. These machines are:

**IBM PC Server 720 (loki)**
Since this machine has 4 Pentium CPUs runing on the Corrollary SMP bus, (and not to mention the MCA cards) most distros will not support more than 1 CPU. I tried to install OS2 (version 2, 3, Warp) but with the IBMServRAID cards could never get it working even though IBM still has information on their website that says how to do it. It doesn't work. 

**Sun SparcStation 2 (shelob)**
I wanted to install either NetBSD or NextStep on it but no matter which CDROM I used couldn't get them to boot. So decided to try out SunOS 4.1.4 but relized really quickly that it was way too ancient and getting it on the network and installing useful software on it would be a big undertaking so went with Solaris 2.6 SPARC. 
NOTE: The LEO graphics card is not well or if at all supported on SS2 machines. Switch to a CG3 or CG6 card to save yourself the hassle.

**On with my notes.**
These are the packages that are needed and I used to build the pkgsrc bootstrap bmake:
1. bison-1.25-local
2. gcc-3.4.6-sol26-sparc-local **(this failed with ERROR: /usr/local/include/c++/3.4.6/sparc-sun-solaris2.6/bits/stdc++.h.gch/O0g file cksum <61659> expected <61787> actual so I renamed it to 00g.org as GCC will fall back to compiling the header from source as needed.)**
3. make-3.82-sol26-sparc-local
4. tar-1.23-sol26-sparc-local
5. gzip-1.2.4-sol26-sparc-local
6. wget-1.7-sol2.6-sparc-local
7. perl-5.005_03-sol26-sparc-local

Since I wanted to use bash and screen so I could disconnect/reconnect to the remote screen, I also installed these:
1. libintl-3.4.0-sol26-sparc-local
2. bash-2.05-sol26-sparc-local
3. libiconv-1.8-sol26-sparc-local.gz
4. screen-4.0.3-sol26-sparc-local
5. ncurses-5.7-sol26-sparc-local
6. libiconv-1.8-sol26-sparc-local 

Solaris 2.6 SPARC local packages are starting to get difficult to find in 2025. Someone has downloaded and submitted the old sunfreeware to Archive.org:
https://archive.org/details/sunfreeware-sol-26
These are also available for now (April 2025) here: http://download.nust.na/pub3/solaris/sunfreeware/pub/unixpackages/sparc/5.6/

For Solaris 2.6 i386 I was unable to find the old sunfreeware locations so went with the work that Tom G. Christensen (swpkg@jupiterrise.com) has made available:
https://jupiterrise.com/tgcware/tgcware.solaris.html

I am uploading both the SPARC and i386 packages here for safe keeping.

Step by step
1. Download all the packages for your arch either from here or from the links above.
2. cd into that folder and run "pkgadd -d <name_of_package>"
3. With the SPARC packages, they will be installed to /usr/local. On the TGZ packages they will be installed to /usr/tgz.
4. Add those paths to your path: export PATH=/usr/local/bin:$PATH (for SPARC) or export PATH=/usr/tgz/bin:$PATH (for i386)
5. On SPARC, cd to /usr/local/, on i386 cd to /usr
6. wget --no-cert https://ftp.netbsd.org/pub/pkgsrc/current/pkgsrc.tar.gz
7. (This will take awhile. On my SS2 it took over night and even on the PC Server 720 took hours) tar -xvzf ./pkgsrc.tar.gz
8. cd pkgsrc/bootstrap
9. Time to build:
10.   SPARC: ./bootstrap --prefix=/usr/pkg --abi=32
11.   i386: ./bootstrap --prefix=/usr/local --abi=32 --compiler=gcc
12. TBD... still trying to get the bootstrap builds to work
