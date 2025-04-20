# Contributing to My Custom Shell

Thank you for your interest in contributing to this project! Here are some guidelines to help you get started.

## Code Style

- Use consistent indentation (2 spaces)
- Keep lines under 80 characters when possible
- Add comments for complex logic
- Follow existing naming conventions

## Pull Request Process

1. Fork the repository
2. Create a new branch for your feature or bugfix
3. Make your changes, ensuring they're well-documented
4. Add or update tests if applicable
5. Submit a pull request with a clear description of the changes

## Development Setup

1. Clone the repository
2. Install required dependencies:
   ```
   # For Debian/Ubuntu
   sudo apt-get install libreadline-dev
   
   # For Red Hat/Fedora
   sudo dnf install readline-devel
   
   # For macOS
   brew install readline
   ```
3. Build the shell with `make`

## Testing

Before submitting your changes, test them thoroughly:

- Try different commands
- Test I/O redirection
- Verify that history is saved correctly
- Check edge cases like empty input

## Reporting Bugs

When reporting bugs, please include:

- Steps to reproduce the issue
- Expected behavior
- Actual behavior
- System information (OS, compiler version, etc.)

## Feature Requests

Feature requests are welcome! Please provide:

- A clear description of the feature
- Why it would be useful
- Any implementation ideas you might have
