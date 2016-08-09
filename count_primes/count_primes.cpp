/**
Description:

Count the number of prime numbers less than a non-negative number, n.
**/

/*Solution_2 埃拉托斯特尼筛法 Sieve of Eratosthenes
如果一个数是另一个数的倍数，那这个数肯定不是素数。利用这个性质，我们可以建立一个素数数组，
从2开始将素数的倍数都标注为不是素数。第一轮将4、6、8等表为非素数，然后遍历到3，发现3没有被标记为非素数，
则将6、9、12等标记为非素数，一直到N为止，再数一遍素数数组中有多少素数。
*/

/*
time: O(N * loglogN)
space: O(n)
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) {
            return 0;
        }

        int res = 0;
        vector<bool> record(n, false);
        for(int i = 2; i < n; i++) {
            if(record[i] == false) {
                res += 1;
                for(int j = i * 2; j < n; j += i) {
                    record[j] = true;
                }
            }
        }

        return res;
    }
};

/*Solution_1*/
/*
time: O(N * logN * time_of_sqrt)
space: O(1)
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) {
            return 0;
        }

        int res = 1;
        for(int i = 3; i < n; i++) {
            if(isPrime(i)) {
                res += 1;
            }
        }

        return res;
    }

    bool isPrime(int num) {
        for(int i = 2; i < sqrt(num) + 1; i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
};
