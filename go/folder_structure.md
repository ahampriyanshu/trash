### Every Go project should follow a defined structure

* Run the following commands(replace ``priyanshumay`` with whatever you like)
```bash
mkdir go && cd go
mkdir bin src && cd src
mkdir github.com && cd github.com
mkdir priyanshumay && cd priyanshumay 
mkdir me-learning-go && cd me-learning-go
```
* Your project's structure should like
```go
.
├── bin
│   └── 
└── src
    └── github.com
        └── priyanshumay
            └── me-learning-go
```

* At the end , the project's folder structures should like:
```go
.
├── bin
│   └── 03_packages
└── src
    └── github.com
        └── priyanshumay
            └── me-learning-go
                ├── 01_hello_world
                │   └── main.go
                ├── 02_var
                │   └── main.go
                ├── 03_packages
                │   ├── main.go
                │   └── strutil
                │       └── reverse.go
                ├── 04_functions
                │   └── main.go
                ├── 05_arrays_slices
                │   └── main.go
                ├── 06_conditionals
                │   └── main.go
                ├── 07_loops
                │   └── main.go
                ├── 08_maps
                │   └── main.go
                ├── 09-range
                │   └── main.go
                ├── 10_pointers
                │   └── main.go
                ├── 11_closures
                │   └── main.go
                ├── 12_structs
                │   └── main.go
                ├── 13_interfaces
                │   └── main.go
                └── 14_web
                    └── main.go
```