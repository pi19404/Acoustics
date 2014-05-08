=========
README
=========

This is the Readme file for the High Performance DSP Utility Application (hua). This  is a CCS project directory.

The Application demonstrates, through illustrative code and web pages, how you can interface your own DSP application to the various Texas Instruments Software Development Kits.

The software development kits supported with this release are:
 - Multi-Core Software Development Kit (MCSDK)
 - SYS/BIOS 6
 - Network Development Kit (NDK)
 - Chip Support Library (CSL)
 - Platform Library.   


Directory structure
===================	
Following is the directory structure:

----- docs - Contains the release notes and users guide for this application.
 |
 |
 ---- Debug - After a successful debug build this directory will contain the 
 |      hpdspua.out and hpdspua.map files.
 |
 ---- Release - After a successful release build this directory will contain the 
 |      hpdpsua.out and hpdspua.map files.
 |
 ---- src - This directory contains most of the source (.c) files 
 |
 |   src/benchmark - This directory contains the source files used for the benchmark tests.
 |
 |   src/java_applet - This directory contains the java code for the java applets we use. 
 |     Java applets must be built with an IDE that supports building java and java applets.
 |     You can download one from Eclipse. 
 |
 |   src/webpages - Webpages and source related to building and displaying the webpages.
 |
 |   src/system - Files used to tailor the application to the platform.
 |
 ---- Readme.txt - This file
 |
 |
 ---- evm.cfg - Our RTSC configuration file. See the users guide in the docs directory 
 |     for more information.
 

Step to build
================
1.) Import the Project into Code Composer using File->Import->Existing CCS Project.
2.) Set the active build type to Release or Debug and then Build.

