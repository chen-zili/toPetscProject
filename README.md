# toPetscProject
用于linux下petsc项目的快速构建

### lib
    single          float(4 byte)       for field solve
    double          double(8 byte)      for time series

In petsc ts, double must be used

### Cmake
    pkg-config     sudo apt-get install pkg-config
    lib            copy the petsclib folder to your project