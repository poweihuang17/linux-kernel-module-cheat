# CONTRIBUTING

Testing you should do before pushing: new modules:

- `/insrm.sh module 5`. Helps catch simple insert remove problems.

New arch:

- `./build -a ARCH && ./run -a ARCH`
- `wget google.com && cat index.html` for Internet
- `./run -a ARCH -d` and `./rungdb -a ARCH`
