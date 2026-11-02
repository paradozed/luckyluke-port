# Agent Development Guide

A file for [guiding AI coding agents](https://agents.md/).

## Projet Overview

The project's goal is to port Lucky Luke game to PC Linux x64. Our strategy is :
- decompile the original game code into human-readable C code
- do not modify original game assets or 'Lucky.exe'
- Validate binary signatures, lengths, and bounds before parsing; report actionable errors for malformed data or missing external tools.
- always git commit after significant change
