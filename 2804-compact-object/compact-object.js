/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        return obj
            .map(compactObject)               
            .filter(Boolean);                  
    } else if (obj !== null && typeof obj === 'object') {
        let res = {};
        for (let key in obj) {
            const val = compactObject(obj[key]);
            if (Boolean(val)) res[key] = val;  
        }
        return res;
    } else {
        return obj;
    }
};