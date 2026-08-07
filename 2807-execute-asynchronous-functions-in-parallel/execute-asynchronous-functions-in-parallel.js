/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let completed = 0;

        functions.forEach((fn, index) => {
            fn()
                .then((result) => {
                    results[index] = result; // Store the result in the same order
                    completed += 1;
                    if (completed === functions.length) {
                        resolve(results); // Resolve when all promises are fulfilled
                    }
                })
                .catch((error) => {
                    reject(error); // Reject if any promise fails
                });
        });
    }) 
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */