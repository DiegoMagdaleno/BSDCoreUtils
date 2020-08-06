
<p align="center">
<img src="https://i.imgur.com/j5LtoWw.png" width=65% height=65%/>
</p>


## The \*BSD utils project

This project is GNU coreutils-like collection of utilities from the OpenBSD and FreeBSD source code. The intent is to offer a BSD-licensed and lightweight replacement for the GNU coreutils project.

## Table of notes

- [Installation](#installation)
- [Contributing](#contributing)

## Installation

Here are some instructions to get this collection of tools running on your computer!

**Option 1 - Precompiled bin**:

If you don't wish to compile, there is a precompiled bin options, for the macOS operating system.

In order to achieve this, just follow this instructions:

1. Install [Homebrew](https://brew.sh/) for macOS.
2. Go to your terminal, and execute the following command `brew tap diegomagdaleno/homebrew-diegoutils`
3. Now run `brew install bsd-coreutils`

_Note: This tools will be installed with the "b" prefix, for example "bcat" instead of "cat"._
_Note 2: BSDCoreutils precompiled bins will be available for diverse Linux distributions eventually_

**Option 2 - From source**:

Building from source is a recommended option if you want to read and wish to take control over what you install on your computer.

1. Make sure you have `openssl` installed, including development libraries (Header files, etc).
2. Make sure you have GNU build tools installed (Ironic), like `autoconf`, `automake` etc.
3. Open your terminal, and run `./autogen.sh`
4. Now run `./configure --program-prefix=b`
5. Run `make install` or `sudo make install`

_Note: --program-prefix is not required, however, it is recommended so it doesn't conflict with your distribution's coreutils, which can cause tons of problems_

## Contributing

Contributions are welcome and encouraged.

If you would like to contribute please do the following:

  - **Contributing code**:
 
    If you decide to contribute to this project here are the instructions to get you started ^_^
    
    It is recommened that you contribute fixes to tools, or other tools from other BSD Systems, make sure they are under the BSD license.

      1. Fork this repository
      2. Git clone this repository into your computer
      3. Hack it and have fun.
      4. Push and submit a pull request!
      
  - **Contributing ideas and requests**:
      
      If you like and enjoy this collection of tools, but however, you think something is missing feel free to recommend it like this:
      
      1. Open a new GitHub issue
      2. Submit with a good explanation what your feature should do
      3. Be patient, I do this in my free time
      
      Some notes: Please don't ask for features that break our BSD mindset like the inclution of `--long-flags`
      
  - **Contributing love and fun**:
 
    Sure you can, if you really enjoy this collection of utilities, you can send me an email or tweet, saying how it helps you, it means a lot.
    
    However, in this case, I think is our friend [David Cantrell](https://github.com/dcantrell) that deserves your love and credit, he did all of the hardwork to make this beatiful set of tools possible.
    


