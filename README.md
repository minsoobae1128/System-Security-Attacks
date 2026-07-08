# SWE3025-01 Homework 2: System Exploitation Techniques

**Author:** 배민수 (Minsoo Bae)  
**Institution:** Sungkyunkwan University (SKKU)  

## Overview
This repository contains the implementation of three system exploitation techniques targeting specific binary vulnerabilities, developed for the **SWE3025 Computer Security** course. The project explores methods to bypass modern operating system security mitigations (such as NX, PIE, and ASLR) using targeted memory corruption strategies.

All exploits are written in Python 3 using the `pwntools` framework and are fully containerized using Docker to ensure precise environmental replication.

Refer to Computer_Security_Homework_Assignment_2.pdf for environment setup.
---

## Repository Structure

System-Security-Attacks/

├── 1_exploit.py                                 # Exploit script for standard Buffer Overflow (Shellcode)

├── 2_exploit.py                                 # Exploit script for ret2libc bypassing NX bit

├── 3_exploit.py                                 # Exploit script for Return-Oriented Programming bypassing PIE/ASLR

├── Dockerfile                                   # Docker configuration to replicate the vulnerable environment

├── entrypoint.sh                                # Container initialization and environment setup script

├── aslr_on.sh                                   # Shell script to enforce ASLR settings for Q3

├── Computer_Security_Homework_Assignments_2.pdf # Original assignment specifications and constraints

├── Exploitation_Scripts_Report.pdf              # Detailed execution logic and exploit mechanics analysis report

└── README.md                                    # Setup instructions and project overview
