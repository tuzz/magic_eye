## Magic Eye

Coming soon...

## Install

```
# Install dependencies.
brew install opencv

# Create a build directory.
mkdir /tmp/build
cd /tmp/build

# Build and run.
cmake path/to/src
make
./magic_eye
```

## Vim

If you're using Vim, you can speed this up by mapping the build script to a key:

```
:nmap - :w \| !mkdir -p /tmp/build && cd /tmp/build && cmake path/to/src && make && ./magic_eye
```
