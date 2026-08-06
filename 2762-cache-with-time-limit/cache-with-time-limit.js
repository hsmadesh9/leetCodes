/**
 * @return {TimeLimitedCache}
 */
var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let exists = this.cache.has(key);

    if (exists) {
        clearTimeout(this.cache.get(key).timer);
    }

    const timer = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, {
        value: value,
        timer: timer
    });

    return exists;
};

/** 
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cache.has(key)) {
        return this.cache.get(key).value;
    }
    return -1;
};

/** 
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};

/**
 * const obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000)
 * obj.get(1)
 * obj.count()
 */