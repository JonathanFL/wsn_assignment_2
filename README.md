# WSN Assignment 2 - Discrete Cosine Transformation in TelosB Mote/Cooja#

DCT-II transform of a length N signal x is given as,

![picture alt](https://wikimedia.org/api/rest_v1/media/math/render/svg/dce6d60796ea026a5a7564418d130effde90d9cf "DCT II")

Tasks completed are:
- [x] Implemented and measured the execution time and energy consumption for the following cases:
     - [x] N = 256 and M = 75.
     - [x] N = 512 and M = 120.
- [x] Measure the mean square error between the original signal and reconstructed signal for both the cases.
Here N is the signal length and M is the number of selected DCT coefficients.

## Results

N = 512, M = 120

Execution time: 20 minutes

Energy consumption: 

mse = 0.1190

![picture alt](N_512.png "DCT II")

- - - -

N = 256, M = 75

Execution time: 3 minutes

Energy consumption: 

mse = 0.1554

![picture alt](N_256.png "DCT II")
