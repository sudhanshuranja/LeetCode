var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const exists = this.cache.has(key) && this.cache.get(key).expiry > now;

    this.cache.set(key, {
        value: value,
        expiry: now + duration
    });

    return exists;
};

TimeLimitedCache.prototype.get = function(key) {
    const data = this.cache.get(key);

    if (!data) return -1;

    if (Date.now() > data.expiry) {
        this.cache.delete(key);
        return -1;
    }

    return data.value;
};

TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let count = 0;

    for (let [key, data] of this.cache) {
        if (data.expiry > now) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};