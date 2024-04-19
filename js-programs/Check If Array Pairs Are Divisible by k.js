/**
 * @param {number[]} arr
 * @param {number} k
 * @return {boolean}
 */
var canArrange = function (arr, k) {
    const remainderFrequency = arr.reduce((obj, x) => {
        const thisRem = (x % k + k) % k;

        if (obj[thisRem]) obj[thisRem]++;
      
        else {
            obj[thisRem] = 1;
        }
        return obj;
    }, {});

// If we have an odd number of multiples of k, return false
    if (remainderFrequency[0] && remainderFrequency[0] % 2 !== 0) return false;

    for (let [rem, count] of Object.entries(remainderFrequency)) {
        if (rem === '0') continue; // skip zeros

        // The count of k - rem has to be equal to count 
        if (remainderFrequency[k - rem] !== count) return false;
    }

    return true;
};
