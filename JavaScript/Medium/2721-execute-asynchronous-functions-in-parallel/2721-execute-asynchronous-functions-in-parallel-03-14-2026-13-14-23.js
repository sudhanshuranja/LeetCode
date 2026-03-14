/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    
    return new Promise((resolve, reject) => {
        
        let results = new Array(functions.length);
        let completed = 0;
        
        for (let i = 0; i < functions.length; i++) {
            
            functions[i]()
                .then((value) => {
                    
                    results[i] = value;
                    completed++;
                    
                    if (completed === functions.length) {
                        resolve(results);
                    }
                    
                })
                .catch((err) => {
                    reject(err);
                });
        }
        
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */