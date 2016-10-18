# CS510 CW 8

**Author(s):** _\<your name(s)\>_

[![Build Status](https://travis-ci.org/chapman-cs510-2016f/cw-08-YOURNAME.svg?branch=master)](https://travis-ci.org/chapman-cs510-2016f/cw-08-YOURNAME)

**Due date:** 2016/10/25

## Specification

**Note: Remember to use Python 3.**

Complete the following exercises, saving your solutions in the indicated files. 

1. Copy your CW07 julia set modules into CW08. Modify your implementation so that it uses ```numba``` Just-In-Time (JIT) compilation to speed up your code, using the code block below as a guide. Specifically:
    * Import ```numba``` at the top of your module, in addition to ```numpy```.
    * When creating the ```julia``` function that transforms the entire complex plane, include a "decorator" (```@nb.vectorize```) just before your function definition to enable JIT compilation. (See below for the correct type signature.) 
    * Use the vectorization properly when applying the ```julia``` function to your complex plane as a ```numpy``` array (or ```DataFrame```).
1. In a notebook ```julia-benchmark.ipynb```, create a complex plane of size 10000 x 10000 points. First run your ```refresh``` method with the ```numba``` decorator commented out, and use ```%time``` to see how long your old implementation (using just ```numpy``` and vanilla ```python```) takes to compute the set (for an interesting ```c``` value that you like). Then uncomment the decorator to enable the JIT compilation with ```numba```, and again use ```%time``` to refresh the plane. How much faster does the code run after adding this one line of code? Detail your benchmarking investigation in your notebook.
1. Work through the [Julia Overview Slides](http://slides.com/profdressel/julia-overview/). Create the appropriate notebooks and test functions as you follow along. Discuss and ask questions.

```python
import numba as nb

@nb.vectorize([nb.int32(nb.complex128)])
def julia(z):
    # Your previous code here
    pass
```
## Assessment

Analyze in this section what you found useful about this assignment in your own words. Include any lingering questions or comments that you may have.

**CHANGEME**

## Honor Pledge

I pledge that all the work in this repository is my own with only the following exceptions:

* Content of starter files supplied by the instructor;
* Code borrowed from another source, documented with correct attribution in the code and summarized here.

Signed,

**YOURNAME**
